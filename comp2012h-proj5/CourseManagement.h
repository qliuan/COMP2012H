#ifndef COURSEMANAGEMENT_H
#define COURSEMANAGEMENT_H

#include "HashTable.h"
#include <string>

struct Course{
    string key;
    string name;
    int credit;
    
    Course* prev = NULL;
    Course* next = NULL;
    
    bool operator==(const Course& cour){
        for(int i=0;i<key.length();i++){
            if(key[i]!=cour.key[i])
                return false;
        }
        return true;
    }
    bool operator<(const Course& cour){
        for(int i=0;i<key.length();i++){
            int v1;
            int v2;
            if(isdigit(key[i]))
                v1 = key[i] - '0';
            else
                v1 = key[i] - 'A' + 10;
            if(isdigit(cour.key[i]))
                v2 = cour.key[i] - '0';
            else
                v2 = cour.key[i] - 'A' + 10;
            if(v1<v2)
                return true;
            if(v1>v2)
                return false;
        }
        return false;
    }
    bool operator>(const Course& cour){
        for(int i=0;i<key.length();i++){
            int v1;
            int v2;
            if(isdigit(key[i]))
                v1 = key[i] - '0';
            else
                v1 = key[i] - 'A' + 10;
            if(isdigit(cour.key[i]))
                v2 = cour.key[i] - '0';
            else
                v2 = cour.key[i] - 'A' + 10;
            if(v1>v2)
                return true;
            if(v1<v2)
                return false;
        }
        return false;
    }
};

#define COURSE_BUCKETS 17
#define COURSE_BASE 36
typedef HashTable<Course> CourseTable;
typedef List<Course>** CourseLists;

class CourseManagement
{
private:
    CourseTable *courTab;
    int count;
public:
    CourseManagement();
    ~CourseManagement();
    bool Insert(const string&);
    bool Modify(const string&);
    bool Delete(const string&);
    bool Query(const string&);
    Course* Search(const string&);
    
    bool validName(const string&);
    string getName();
    bool validCredit(const string&);
    int getCredit();
    
    CourseLists getLists();
    bool Insert(const string&,const string&,int);
    int getCount();
};


#endif /*COUSEMANAGEMENT_H*/
