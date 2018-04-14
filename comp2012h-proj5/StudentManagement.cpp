#include "StudentManagement.h"
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;

StudentManagement::StudentManagement() : count(0) {
    stuTab = new StudentTable(STUDENT_BUCKETS,STUDENT_BASE);
}

StudentManagement::~StudentManagement() {}

bool StudentManagement::Insert(const string &key){
    
    Student* stu = stuTab->insertNode(key); // stu == NULL if not applicable
    
    if(stu==NULL){
        printf("Student already exist");
        return false;
    }
    printf("Enter the student name: ");
    string name = getName();
    stu->name = name;
    
    printf("Enter the student year [1-3]: ");
    int year = getYear();
    stu->year = year;
    
    printf("Enter the student gender [M,F]: ");
    char gender = getGender();
    stu->gender = gender;
    
    count++;
    printf("Creation of student record successful");
    return true;
}

bool StudentManagement::Modify(const string &key){
    Student* stu = stuTab->modifyNode(key);
    
    if(stu == NULL){
        printf("Student not exist");
        return false;
    }
    
    printf("Enter the student name [%s]: ",stu->name.c_str());
    string name = getName();
    stu->name = name;
    
    printf("Enter the student year [%d]: ",stu->year);
    int year = getYear();
    stu->year = year;
    
    printf("Enter the student gender [%c]: ",stu->gender);
    char gender = getGender();
    stu->gender = gender;
    
    printf("Modification of student record successful");
    return true;
}

bool StudentManagement::Delete(const string &key){
    if(!stuTab->deleteNode(key)){
        printf("Student not exist");
        return false;
    }
    count--;
    printf("Deletion of student record successful");
    return true;
}

bool StudentManagement::Query(const string &key){
    Student* stu = stuTab->queryNode(key);
    if(stu==NULL){
        printf("Student not exist");
        return false;
    }
    printf("\nID:\t\%s\n",stu->key.c_str());
    printf("Name:\t%s\n",stu->name.c_str());
    printf("Year:\t%d\n",stu->year);
    printf("Gender:\t%c\n",stu->gender);
    return true;
}

bool StudentManagement::validName(const string &n){
    int size = n.length();
    if(size==0)
        return false;
    if(size>33)
        return false;
    return true;
}

string StudentManagement::getName(){
    string name = "LIU Qinhan";
    getline(cin,name);
    while(!validName(name)){
        printf("Invalid input, re-enter again [student name]: ");
        getline(cin,name);
    }
    return name;
}

bool StudentManagement::validYear(const string &y){
    if(y.length()!=1||!isdigit(y[0]))
        return false;
    int year = atoi(y.c_str());
    if(year==0)
        return false;
    if(year>3)
        return false;
    return true;
}

int StudentManagement::getYear(){
    string year = "0";
    getline(cin,year);
    while(!validYear(year)){
        printf("Invalid input, re-enter again [student year]: ");
        getline(cin,year);
    }
    return atoi(year.c_str());
}

bool StudentManagement::validGender(const string &g){
    if(g.length()!=1)
        return false;
    if(g[0]=='M'||g[0]=='m'||g[0]=='F'||g[0]=='f')
        return true;
    else
        return false;
}

char StudentManagement::getGender(){
    string gender = "M";
    getline(cin,gender);
    while(!validGender(gender)){
        printf("Invalid input, re-enter again [M,F]: ");
        getline(cin,gender);
    }
    if(gender[0]=='m')
        return 'M';
    if(gender[0]=='f')
        return 'F';
    return gender[0];
}

StudentLists StudentManagement::getLists(){
    return stuTab->getLists();
}

Student* StudentManagement::Search(const string &key){
    Student *stu = stuTab->searchNode(key);
    if(stu==NULL)
        return NULL;
    else
        return stu;
}

bool StudentManagement::Insert(const string &key,const string &name,int year,char gender){
    Student* stu = stuTab->insertNode(key); // stu == NULL if not applicable
    if(stu==NULL){
        stu = stuTab->modifyNode(key);
        stu->name = name;
        stu->year = year;
        stu->gender = gender;
        return false;
    }
    else{
        stu->name = name;
        stu->year = year;
        stu->gender = gender;
        count++;
    }
    return true;
}

int StudentManagement::getCount(){
    return count;
}
