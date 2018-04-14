#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H

#include "HashTable.h"
#include <string>


struct Student{
    string key;
    string name;
    int year;
    char gender;
    
    Student* prev = NULL;
    Student* next = NULL;
    
    bool operator==(const Student& stu){
        for(int i=0;i<key.length();i++){
            if(key[i]!=stu.key[i])
                return false;
        }
        return true;
    }
    bool operator<(const Student& stu){
        for(int i=0;i<key.length();i++){
            if( (key[i]-'0')<(stu.key[i]-'0') )
                return true;
            if( (key[i]-'0')>(stu.key[i]-'0') )
                return false;
        }
        return false;
    }
    bool operator>(const Student& stu){
        for(int i=0;i<key.length();i++){
            if( (key[i]-'0')>(stu.key[i]-'0') )
                return true;
            if( (key[i]-'0')<(stu.key[i]-'0') )
                return false;
        }
        return false;
    }
};

#define STUDENT_BUCKETS 29
#define STUDENT_BASE 10
typedef HashTable<Student> StudentTable;
typedef List<Student>** StudentLists;

class StudentManagement{
private:
    StudentTable *stuTab;
    int count;
public:
    StudentManagement();
    ~StudentManagement();
    bool Insert(const string&);
    bool Modify(const string&);
    bool Delete(const string&);
    bool Query(const string&);
    Student* Search(const string&);
    
    bool validName(const string&);
    string getName();
    bool validYear(const string&);
    int getYear();
    bool validGender(const string&);
    char getGender();
    
    StudentLists getLists();
    bool Insert(const string&,const string&,int,char);
    int getCount();
};

#endif /*STUDENTMANAGEMENT_H*/
