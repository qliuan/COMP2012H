#include "CourseManagement.h"
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;

CourseManagement::CourseManagement() : count(0) {
    courTab = new CourseTable(COURSE_BUCKETS,COURSE_BASE);
}

CourseManagement::~CourseManagement() {}

bool CourseManagement::Insert(const string &key){
    Course* cour = courTab->insertNode(key); // cour == NULL if not applicable
    
    if(cour==NULL){
        printf("Course already exist");
        return false;
    }
    printf("Enter the course name: ");
    string name = getName();
    cour->name = name;
    
    printf("Enter the course credit [0-5]: ");
    int credit = getCredit();
    cour->credit = credit;
    
    count++;
    printf("Creation of course record successful");
    return true;
}

bool CourseManagement::Modify(const string &key){
    Course* cour = courTab->modifyNode(key); // cour == NULL if not applicable
    
    if(cour==NULL){
        printf("Course not exist");
        return false;
    }
    
    printf("Enter the course name: ");
    string name = getName();
    cour->name = name;
    
    printf("Enter the course credit [0-5]: ");
    int credit = getCredit();
    cour->credit = credit;
    
    printf("Modification of course record successful");
    return true;
}

bool CourseManagement::Delete(const string &key){
    if(!courTab->deleteNode(key)){
        printf("Course not exist");
        return false;
    }
    count--;
    printf("Deletion of course record successful");
    return true;
}

bool CourseManagement::Query(const string &key){
    Course* cour = courTab->queryNode(key);
    if(cour==NULL){
        printf("Course not exist");
        return false;
    }
    printf("Code:\t%s\n",cour->key.c_str());
    printf("Name:\t%s\n",cour->name.c_str());
    printf("Credit:\t%d\n",cour->credit);
    return true;
}

Course* CourseManagement::Search(const string &key){
    Course* cour = courTab->searchNode(key);
    if(cour==NULL)
        return NULL;
    else
        return cour;
}


bool CourseManagement::validName(const string &n){
    if(n.length()<1||n.length()>32)
        return false;
    return true;
}

string CourseManagement::getName(){
    string name;
    getline(cin,name);
    while(!validName(name)){
        printf("Invalid input, re-enter again [course name]: ");
        getline(cin,name);
    }
    return name;
}

bool CourseManagement::validCredit(const string &c){
    if(c.length()!=1||!isdigit(c[0]))
        return false;
    
    int credit = atoi(c.c_str());
    if(credit>5)
        return false;
    
    return true;
}

int CourseManagement::getCredit(){
    string credit = "0";
    getline(cin,credit);
    while(!validCredit(credit)){
        printf("Invalid input, re-enter again [course credit]: ");
        getline(cin,credit);
    }
    return atoi(credit.c_str());
}

CourseLists CourseManagement::getLists(){
    return courTab->getLists();
}

bool CourseManagement::Insert(const string &key,const string &name,int credit){
    Course* cour = courTab->insertNode(key); // cour == NULL if not applicable
    if(cour==NULL){
        cour = courTab->modifyNode(key);
        cour->name = name;
        cour->credit = credit;
        return false;
    }
    else{
        cour->name = name;
        cour->credit = credit;
        count++;
        return true;
    }
}

int CourseManagement::getCount(){
    return count;
}

