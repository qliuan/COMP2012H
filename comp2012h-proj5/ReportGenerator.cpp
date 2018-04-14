#include "ReportGenerator.h"

#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ReportGenerator::ReportGenerator(StudentManagement* s,CourseManagement* c,Registration* r)
: stuMana(s),courMana(c),regist(r)	{}

ReportGenerator::~ReportGenerator() {}

bool ReportGenerator::Students(){
    string filename = "Students.html";
    ofstream fout(filename.c_str());
    assert (fout.is_open());
    fout << "<HTML>" << endl;
    fout << "<HEAD>" << endl;
    fout << "<HEAD>" << endl;
    fout << "<TITLE>All Students List</TITLE>" << endl;
    fout << "</HEAD>" << endl;
    fout << "<BODY bgColor=#ffffcc>" << endl;
    fout << "<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>" << endl;
    fout << "<H2>All Students List</H2>" << endl;
    
    if(stuMana->getCount()==0){
        fout << "<P>" << endl;
        fout << "No student found" << endl;
        fout << "</P>" << endl;
    }
    else{
        fout << "<P>" << endl;
        fout << "<TABLE cellSpacing=1 cellPadding=1 border=1>" << endl;
        fout << endl;
        
        fout << "<TR>" << endl;
        fout << "<TD>Student ID</TD>" << endl;
        fout << "<TD>Student Name</TD>" << endl;
        fout << "<TD>Year</TD>" << endl;
        fout << "<TD>Gender</TD>" << endl;
        fout << "</TR>" << endl;
        
        List<Student>* *stuLists = stuMana->getLists();
        for(int i=0;i<29;i++){
            List<Student>* stuList = stuLists[i];
            Student* head = stuList->getHead();
            Student* end = stuList->getEnd();
            if(head == NULL) // no node in list
                continue;
            else if(head == end){ // one node in list
                fout << "<TR>" << endl;
                fout << "<TD>" << head->key << "</TD>" << endl;
                fout << "<TD>" << head->name << "</TD>" << endl;
                fout << "<TD>" << head->year << "</TD>" << endl;
                if(head->gender == 'M')
                    fout << "<TD>Male</TD>" << end;
                else // head->gender == 'F'
                    fout << "<TD>Female</TD>" << end;
                fout << "</TR>" << endl;
            }
            else{ // more than one node
                Student* iter = head;
                do{
                    fout << "<TR>" << endl;
                    fout << "<TD>" << iter->key << "</TD>" << endl;
                    fout << "<TD>" << iter->name << "</TD>" << endl;
                    fout << "<TD>" << iter->year << "</TD>" << endl;
                    if(iter->gender == 'M')
                        fout << "<TD>Male</TD>" << end;
                    else // iter->gender == 'F'
                        fout << "<TD>Female</TD>" << end;
                    fout << "</TR>" << endl;
                    
                    iter = iter->next;
                }while(iter!=head);
            }
        }
        
        fout << endl;
        fout << "</TABLE>" << endl;
        fout << "</P>" << endl;
    }
    
    fout << "</BODY>" << endl;
    fout << "</HTML>" << endl;
    
    printf("Output Successful");
    return true;
}

bool ReportGenerator::Courses(){
    string filename = "Courses.html";
    ofstream fout(filename.c_str());
    assert (fout.is_open ());
    fout << "<HTML>" << endl;
    fout << "<HEAD>" << endl;
    fout << "<HEAD>" << endl;
    fout << "<TITLE>All Courses List</TITLE>" << endl;
    fout << "</HEAD>" << endl;
    fout << "<BODY bgColor=#ffffcc>" << endl;
    fout << "<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>" << endl;
    fout << "<H2>All Courses List</H2>" << endl;
    
    if(courMana->getCount()==0){
        fout << "<P>" << endl;
        fout << "No course found" << endl;
        fout << "</P>" << endl;
    }
    else{
        fout << "<P>" << endl;
        fout << "<TABLE cellSpacing=1 cellPadding=1 border=1>" << endl;
        fout << endl;
        
        fout << "<TR>" << endl;
        fout << "<TD>Course Code</TD>" << endl;
        fout << "<TD>Course Name</TD>" << endl;
        fout << "<TD>Credit</TD>" << endl;
        fout << "</TR>" << endl;
        
        List<Course>* *courLists = courMana->getLists();
        for(int i=0;i<17;i++){
            List<Course>* courList = courLists[i];
            Course* head = courList->getHead();
            Course* end = courList->getEnd();
            if(head == NULL) // no node in list
                continue;
            else if(head == end){ // one node in list
                fout << "<TR>" << endl;
                fout << "<TD>" << head->key << "</TD>" << endl;
                fout << "<TD>" << head->name << "</TD>" << endl;
                fout << "<TD>" << head->credit << "</TD>" << endl;
                fout << "</TR>" << endl;
            }
            else{ // more than one node
                Course* iter = head;
                do{
                    fout << "<TR>" << endl;
                    fout << "<TD>" << iter->key << "</TD>" << endl;
                    fout << "<TD>" << iter->name << "</TD>" << endl;
                    fout << "<TD>" << iter->credit << "</TD>" << endl;
                    fout << "</TR>" << endl;
                    
                    iter = iter->next;
                }while(iter!=head);
            }
        }
        
        fout << endl;
        fout << "</TABLE>" << endl;
        fout << "</P>" << endl;
    }
    
    fout << "</BODY>" << endl;
    fout << "</HTML>" << endl;
    
    printf("Output Successful");
    return true;
}

bool ReportGenerator::StudentRegs(){
    printf("Enter the student ID: ");
    string id = getId();
    Student *stu = stuMana->Search(id);
    
    if(stu == NULL){
        printf("Student not exist");
        return false;
    }
    
    string filename = id + ".html";
    ofstream fout(filename.c_str());
    assert (fout.is_open ());
    fout << "<HTML>" << endl;
    fout << "<HEAD>" << endl;
    fout << "<HEAD>" << endl;
    fout << "<TITLE>Course Records for Student " << id << "</TITLE>" << endl;
    fout << "</HEAD>" << endl;
    fout << "<BODY bgColor=#ffffcc>" << endl;
    fout << "<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>" << endl;
    fout << "<H2>Course Records for Student: " << stu->name << " (" << id << ")</H2>" << endl;
    fout << "<P>" << endl;
    fout << "<TABLE cellSpacing=1 cellPadding=1 border=1>" << endl;
    fout << endl;
    
    fout << "<TR>" << endl;
    fout << "<TD>Course Code</TD>" << endl;
    fout << "<TD>Course Name</TD>" << endl;
    fout << "<TD>Credit</TD>" << endl;
    fout << "<TD>Exam Mark</TD>" << endl;
    fout << "</TR>" << endl;
    
    Index *iter = regist->searchStudent(id);
    if(iter!=NULL){
        Record *rec = iter->rec;
        Course *cour = courMana->Search(rec->courCode);
        Course *ref = cour;
        bool finished = false;
        
        while(!finished){
            fout << "<TR>" << endl;
            fout << "<TD>" << cour->key << "</TD>" << endl;
            fout << "<TD>" << cour->name << "</TD>" << endl;
            fout << "<TD>" << cour->credit << "</TD>" << endl;
            if(rec->mark==NULL)
                fout << "<TD>N/A</TD>" << endl;
            else
                fout << "<TD>" << rec->mark << "</TD>" << endl;
            fout << "</TR>" << endl;
            
            iter = iter->next;
            rec = iter->rec;
            cour = courMana->Search(rec->courCode);
            
            // check the id of next node
            for(int i=0;i<id.length();i++){
                if(id[i]!=iter->key[i])
                    finished = true;
            }
            // check whether it loops again
            if( (*cour)==(*ref) )
                finished = true;
        }
    }
    
    fout << "</TABLE>" << endl;
    fout << "</P>" << endl;
    fout << "</BODY>" << endl;
    fout << "</HTML>" << endl;
    
    printf("Output Successful");
    return true;
}

bool ReportGenerator::CourseRegs(){
    printf("Enter the course code: ");
    string code = getCode();
    Course *cour = courMana->Search(code);
    
    if(cour == NULL){
        printf("Course not exist");
        return false;
    }
    
    string filename = code + ".html";
    ofstream fout(filename.c_str());
    assert (fout.is_open ()); 
    fout << "<HTML>" << endl;
    fout << "<HEAD>" << endl;
    fout << "<HEAD>" << endl;
    fout << "<TITLE>Course Records for Course " << cour << "</TITLE>" << endl;
    fout << "</HEAD>" << endl;
    fout << "<BODY bgColor=#ffffcc>" << endl;
    fout << "<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>" << endl;
    fout << "<H2>Course Records for Course: " << cour->name << " (" << code << ")</H2>" << endl;
    fout << "<P>" << endl;
    fout << "<TABLE cellSpacing=1 cellPadding=1 border=1>" << endl;
    fout << endl;
    
    fout << "<TR>" << endl;
    fout << "<TD>Student ID</TD>" << endl;
    fout << "<TD>Student Name</TD>" << endl;
    fout << "<TD>Year</TD>" << endl;
    fout << "<TD>Gender</TD>" << endl;
    fout << "<TD>Exam Mark</TD>" << endl;
    fout << "</TR>" << endl;
    
    Index *iter = regist->searchCourse(code);
    if(iter!=NULL){
        Record *rec = iter->rec;
        Student *stu = stuMana->Search(rec->stuId);
        Student *ref = stu;
        bool finished = false;
        
        while(!finished){
            fout << "<TR>" << endl;
            fout << "<TD>" << stu->key << "</TD>" << endl;
            fout << "<TD>" << stu->name << "</TD>" << endl;
            fout << "<TD>" << stu->year << "</TD>" << endl;
            if(stu->gender=='M')
                fout << "<TD>Male</TD>" << endl;
            else
                fout << "<TD>Female</TD>" << endl;
            if(rec->mark==NULL)
                fout << "<TD>N/A</TD>" << endl;
            else
                fout << "<TD>" << rec->mark << "</TD>" << endl;
            fout << "</TR>" << endl;
            
            iter = iter->next;
            rec = iter->rec;
            stu = stuMana->Search(rec->stuId);
            
            // check the code of next node
            for(int i=0;i<code.length();i++){
                if(code[i]!=iter->key[i])
                    finished = true;
            }
            
            // check whether it loops again
            if( (*stu)==(*ref) )
                finished = true;
        }
    }
    
    fout << "</TABLE>" << endl;
    fout << "</P>" << endl;
    fout << "</BODY>" << endl;
    fout << "</HTML>" << endl;
    
    printf("Output Successful");
    return true;
}

bool ReportGenerator::validId(const string &i){
    if(i.length()!=8)
        return false;
    for(int j;j<i.length();j++){
        if(!isdigit(i[j]))
            return false;
    }
    return true;
}

string ReportGenerator::getId(){
    string id = "00000000";
    getline(cin,id);
    while(!validId(id)){
        printf("Invalid input, re-enter again [student ID]: ");
        getline(cin,id);
    }
    return id;
}

bool ReportGenerator::validCode(const string &c){
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

string ReportGenerator::getCode(){
    string code = "XXXX0000";
    getline(cin,code);
    while(!validCode(code)){
        printf("Invalid input, re-enter again [course code]: ");
        getline(cin,code);
    }
    return code;
}

