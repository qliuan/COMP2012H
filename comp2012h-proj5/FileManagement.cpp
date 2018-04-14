#include "FileManagement.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

FileManagement::FileManagement(StudentManagement* s,CourseManagement* c,Registration* r) : stuMana(s),courMana(c),regist(r) {}

FileManagement::~FileManagement() {}

bool FileManagement::Load(){
    printf("Enter the filename: ");
    string filename;
    getline(cin,filename);
    ifstream fin(filename.c_str());
    if(!fin.is_open()){
        printf("Error: Load File Error (File not exist / File Corrupted / Incorrect Format)");
        return false;
    }
    string line;
    getline(fin,line);
    // Load student records
    if(checkStudent(line)){
        getline(fin,line);
        getline(fin,line);
    }
    while(!checkCourse(line)){
        string id = line;
        string name;
        getline(fin,name);
        string year;
        getline(fin,year);
        string gender;
        getline(fin,gender);
        stuMana->Insert(id,name,atoi(year.c_str()),gender[0]);
        
        getline(fin,line);
        getline(fin,line);
    }
    // Load course records
    if(checkCourse(line)){
        getline(fin,line);
        getline(fin,line);
    }
    while(!checkRegistration(line)){
        string code = line;
        string name;
        getline(fin,name);
        string credit;
        getline(fin,credit);
        courMana->Insert(code,name,atoi(credit.c_str()));
        
        getline(fin,line);
        getline(fin,line);
    }
    // Load registration records
    if(checkRegistration(line)){
        getline(fin,line);
    }
    while(getline(fin,line)){
        string id = line;
        string code;
        getline(fin,code);
        string mark;
        getline(fin,mark);
        regist->Add(id,code,atoi(mark.c_str()));
        
        getline(fin,line);
    }
    
    printf("Loading Successful");
    return true;
}

bool FileManagement::Save(){
    printf("Enter the filename: ");
    string filename;
    getline(cin,filename);
    ofstream fout(filename.c_str());
    if(!fout.is_open()){
        printf("Error: Open File Error");
        return false;
    }
    // Output student records
    StudentLists stuLists = stuMana->getLists();
    fout << "Student Records" << endl;
    fout << endl;
    for(int i=0;i<29;i++){
        List<Student>* stuList = stuLists[i];
        Student* head = stuList->getHead();
        Student* end = stuList->getEnd();
        if(head == NULL) // no node in list
            continue;
        else if(head == end){ // one node in list
            fout << head->key << endl;
            fout << head->name << endl;
            fout << head->year << endl;
            fout << head->gender << endl;
            fout << endl;
        }
        else{ // more than one node
            Student* iter = head;
            do{
                fout << iter->key << endl;
                fout << iter->name << endl;
                fout << iter->year << endl;
                fout << iter->gender << endl;
                fout << endl;
                
                iter = iter->next;
            }while(iter!=head);
        }
    }
    // Output course records
    CourseLists courLists = courMana->getLists();
    fout << "Course Records" << endl;
    fout << endl;
    for(int i=0;i<17;i++){
        List<Course>* courList = courLists[i];
        Course* head = courList->getHead();
        Course* end = courList->getEnd();
        if(head == NULL) // no node in list
            continue;
        else if(head == end){ // one node in list
            fout << head->key << endl;
            fout << head->name << endl;
            fout << head->credit << endl;
            fout << endl;
        }
        else{ // more than one node
            Course* iter = head;
            do{
                fout << iter->key << endl;
                fout << iter->name << endl;
                fout << iter->credit << endl;
                fout << endl;
                
                iter = iter->next;
            }while(iter!=head);
        }
    }
    // Output registration records
    Record *recHead = regist->getHead();
    Record *recEnd = regist->getEnd();
    fout << "Registration Records" << endl;
    fout << endl;
    if(recHead!=NULL){
        if(recHead==recEnd){ // only one registration record
            fout << recHead->stuId << endl;
            fout << recHead->courCode << endl;
            fout << recHead->mark << endl;
            fout << endl;
        }
        else{
            Record *iter = recHead;
            do{
                fout << iter->stuId << endl;
                fout << iter->courCode << endl;
                fout << iter->mark << endl;
                fout << endl;
                
                iter = iter->next;
            }while(iter!=recHead);
        }
    }
    
    printf("Saving Successful");
    return true;
}

bool FileManagement::checkStudent(const string &line){
    string start = "Student Records";
    if(line.length()!=start.length())
        return false;
    else{
        for(int i=0;i<start.length();i++){
            if(line[i]!=start[i])
                return false;
        }
        return true;
    }
}

bool FileManagement::checkCourse(const string &line){
    string start = "Course Records";
    if(line.length()!=start.length())
        return false;
    else{
        for(int i=0;i<start.length();i++){
            if(line[i]!=start[i])
                return false;
        }
        return true;
    }
}

bool FileManagement::checkRegistration(const string &line){
    string start = "Registration Records";
    if(line.length()!=start.length())
        return false;
    else{
        for(int i=0;i<start.length();i++){
            if(line[i]!=start[i])
                return false;
        }
        return true;
    }
}
