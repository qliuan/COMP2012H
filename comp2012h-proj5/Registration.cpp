#include "Registration.h"
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;

Registration::Registration(StudentManagement *s,CourseManagement *c) : stuMana(s), courMana(c),
head(NULL),end(NULL),nextRecord(NULL) {
    idTab = new IndexTable(ID_BUCKETS,ID_BASE);
    codeTab = new IndexTable(CODE_BUCKETS,CODE_BASE);
}

Registration::~Registration() {}

bool Registration::Add(){
    printf("Enter the student ID: ");
    string stuId = getId();
    if(!stuMana->Search(stuId)){
        printf("student not exist");
        return false;
    }
    
    printf("Enter the course code: ");
    string courCode = getCode();
    if(!courMana->Search(courCode)){
        printf("course not exist");
        return false;
    }
    
    Record *rec = new Record;
    rec->stuId = stuId;
    rec->courCode = courCode;
    
    // insert into the right position
    if(searchRecord(stuId,courCode)){
        printf("The student already registered the course");
        return false;
    }
    else{
        if(head==end && head==NULL){
            head = rec;
            end = rec;
            rec->prev = end;
            rec->next = head;
        }
        else{	// find the position for the new record
            if(nextRecord == head){
                head->prev = rec;
                end->next = rec;
                rec->next = head;
                rec->prev = end;
                head = rec;
            }
            else if(nextRecord == NULL){
                end->next = rec;
                head->prev = rec;
                rec->prev = end;
                rec->next = head;
                end = rec;
            }
            else{
                nextRecord->prev->next = rec;
                rec->prev = nextRecord->prev;
                nextRecord->prev = rec;
                rec->next = nextRecord;
            }
        }
    }
    
    // creat corresponding indeces
    Index *id = idTab->insertNode(stuId);
    id->rec = rec;
    rec->idIndex = id;
    Index *code = codeTab->insertNode(courCode);
    code->rec = rec;
    rec->codeIndex = code;
    
    printf("Add course successful");
    return true;
}

bool Registration::Drop(){
    printf("Enter the student ID: ");
    string stuId = getId();
    if(!stuMana->Search(stuId)){
        printf("student not exist");
        return false;
    }
    
    printf("Enter the course code: ");
    string courCode = getCode();
    if(!courMana->Search(courCode)){
        printf("course not exist");
        return false;
    }
    
    // delete the record together with its two indeces
    Record *rec = searchRecord(stuId,courCode);
    if(rec == NULL){
        printf("The registration record not exist");
        return false;
    }
    else{
        if(head!=NULL && head==end){ // only one record
            head = end = NULL;
        }
        else{
            if(rec == head)
                head = head->next;
            if(rec == end)
                end = end->prev;
            rec->prev->next = rec->next;
            rec->next->prev = rec->prev;
        }
        deleteIndexes(rec);
        delete rec;
        printf("Drop course successful");
        return true;
    }
}

bool Registration::Modify(){
    printf("Enter the student ID: ");
    string stuId = getId();
    if(!stuMana->Search(stuId)){
        printf("student not exist");
        return false;
    }
    
    printf("Enter the course code: ");
    string courCode = getCode();
    if(!courMana->Search(courCode)){
        printf("course not exist");
        return false;
    }
    // search the record
    Record *rec = searchRecord(stuId,courCode);
    if(rec == NULL){
        printf("The registration record not exist");
        return false;
    }
    else{
        if(rec->mark==NULL)
            printf("Enter the exam mark [N/A]: ");
        else
            printf("Enter the exam mard [%d]: ",rec->mark);
        int mark = getMark();
        rec->mark = mark;
        printf("Modification of exam mark successful");
        return true;
    }
}

bool Registration::Query(){
    printf("Enter the student ID: ");
    string stuId = getId();
    if(!stuMana->Search(stuId)){
        printf("student not exist");
        return false;
    }
    
    printf("Enter the course code: ");
    string courCode = getCode();
    if(!courMana->Search(courCode)){
        printf("course not exist");
        return false;
    }
    
    Record *rec = searchRecord(stuId,courCode);
    if(rec == NULL){
        printf("The registration record not exist");
        return false;
    }
    else{
        printf("Student ID:\t%s\n",rec->stuId.c_str());
        printf("Course Code:\t%s\n",rec->courCode.c_str());
        if(rec->mark==NULL)
            printf("Exam Mark:\t[N/A]");
        else
            printf("Exam Mark:\t[%d]",rec->mark);
        return true;
    }
}


Record* Registration::searchRecord(const string &id, const string &code){
    Record *iter = head;
    Record *rec = new Record;
    rec->stuId = id;
    rec->courCode = code;
    
    if(iter==NULL)
        return NULL;
    if( (*head)>(*rec) ){
        nextRecord = head;
        return NULL;
    }
    if( (*end)<(*rec) ){
        nextRecord = NULL;
        return NULL;
    }
    
    while( (*iter)<(*rec) ){
        iter = iter->next;
    }
    if( (*iter)==(*rec) ){
        return iter;
    }
    else{
        nextRecord = iter;
        return NULL;
    }
}

void Registration::deleteIndexes(Record *rec){
    // delete id index
    Index *idIter = rec->idIndex;
    while(!( (*idIter->rec)==(*rec) )){// look for the index
        idIter = idIter->next;
    }
    
    IndexList *idList = idTab->getList(rec->stuId);
    idList->updateList(idIter);
    idIter->prev->next = idIter->next;
    idIter->next->prev = idIter->prev;
    delete idIter;
    
    // delete code index
    Index *codeIter = rec->codeIndex;
    while(!( (*codeIter->rec)==(*rec) )){// look for the index
        codeIter = codeIter->next;
    }
    
    IndexList *codeList = codeTab->getList(rec->courCode);
    codeList->updateList(codeIter);
    codeIter->prev->next = codeIter->next;
    codeIter->next->prev = codeIter->prev;
    delete codeIter;
}

bool Registration::deleteStudent(const string &id){
    
    Index *idIter = searchStudent(id);
    if(idIter==NULL)
        return false;
    
    Index *ref = new Index;
    ref->key = id;
    bool finished = false;
    while(!finished){
        deleteIndexes(idIter->rec);
        if(idIter->key.length()==0)  finished = true;
        else idIter = idIter->next;
        if( !finished && !((*idIter)==ref) )// not the same student
            finished = true;
    }
    delete ref;
    return true;
}

bool Registration::emptyCourse(const string &code){
    Index *codeIter = searchCourse(code);
    if(codeIter==NULL)
        return true;
    else
        return false;
}

Index* Registration::searchStudent(const string &id){
    Index *node = new Index;
    node->key = id;
    Index *idIndex = idTab->searchNode(node);
    delete node;
    return idIndex;
}

Index* Registration::searchCourse(const string &code){
    Index *node = new Index;
    node->key = code;
    Index *codeIndex = codeTab->searchNode(node);
    delete node;
    return codeIndex;
}

bool Registration::Add(const string &stuId,const string &courCode,int mark){
    Record *rec = new Record;
    rec->stuId = stuId;
    rec->courCode = courCode;
    rec->mark = mark;
    
    // insert into the right position
    if(searchRecord(stuId,courCode)){ // The student already registered the course
        return false;
    }
    else{
        if(head==end && head==NULL){
            head = rec;
            end = rec;
            rec->prev = end;
            rec->next = head;
        }
        else{	// find the position for the new record
            if(nextRecord == head){
                head->prev = rec;
                end->next = rec;
                rec->next = head;
                rec->prev = end;
                head = rec;
            }
            else if(nextRecord == NULL){
                end->next = rec;
                head->prev = rec;
                rec->prev = end;
                rec->next = head;
                end = rec;
            }
            else{
                nextRecord->prev->next = rec;
                rec->prev = nextRecord->prev;
                nextRecord->prev = rec;
                rec->next = nextRecord;
            }
        }
    }
    
    // creat corresponding indeces
    Index *id = idTab->insertNode(stuId);
    id->rec = rec;
    rec->idIndex = id;
    Index *code = codeTab->insertNode(courCode);
    code->rec = rec;
    rec->codeIndex = code;
    
    return true;
}

Record* Registration::getHead(){
    return head;
}

Record* Registration::getEnd(){
    return end;
}

bool Registration::validId(const string &i){
    if(i.length()!=8)
        return false;
    for(int j;j<i.length();j++){
        if(!isdigit(i[j]))
            return false;
    }
    return true;
}

string Registration::getId(){
    string id = "00000000";
    getline(cin,id);
    while(!validId(id)){
        printf("Invalid input, re-enter again [student ID]: ");
        getline(cin,id);
    }
    return id;
}

bool Registration::validCode(const string &c){
    if(c.length()!=7&&c.length()!=8)
        return false;
    for(int i=0;i<4;i++){
        if(!isupper(c[i]))
            return false;
    }
    for(int i=4;i<c.length();i++){
        if(!isdigit(c[i])&&!isupper(c[i]))
            return false;
    }
    return true;
}

string Registration::getCode(){
    string code = "XXXX0000";
    getline(cin,code);
    while(!validCode(code)){
        printf("Invalid input, re-enter again [course code]: ");
        getline(cin,code);
    }
    return code;
}

bool Registration::validMark(const string &m){
    if(m.length()==0 || m.length()>3)
        return false;
    for(int i=0;i<m.length();i++){
        if(!isdigit(m[i]))
            return false;
    }
    int mark = atoi(m.c_str());
    if(mark<0||mark>100)
        return false;
    
    return true;
}

int Registration::getMark(){
    string mark = "0";
    getline(cin,mark);
    while(!validMark(mark)){
        printf("Invalid input, re-enter again [exam mark]: ");
        getline(cin,mark);
    }
    return atoi(mark.c_str());
}



