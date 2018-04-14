#ifndef UTILITY_H
#define UTILITY_H

#include "StudentManagement.h"
#include "CourseManagement.h"
#include "Registration.h"
#include "ReportGenerator.h"
#include "FileManagement.h"
#include <string>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;

#define MAINMENU_SIZE 6
#define STUDENTMENU_SIZE 5
#define COURSEMENU_SIZE 5
#define REGISTRATIONMENU_SIZE 5
#define REPORTMENU_SIZE 5
#define FILEMENU_SIZE 3

class Utility
{
private:
	StudentManagement* stuMana;
	CourseManagement* courMana;
	Registration* regist;
	ReportGenerator* repoGene;
    FileManagement* fileMana;
public:
    Utility(StudentManagement*,CourseManagement*,Registration*,ReportGenerator*,FileManagement*);
	~Utility();
	
	void readEnter();
	void mainMenu();
	void studentMenu();
	void courseMenu();
	void registrationMenu();
	void reportMenu();
	void fileMenu();
    
    bool validChoice(const string&,int);
    int getChoice(int);
    bool isNum(const string&);
    string getId();
    bool validCode(const string&);
    string getCode();
};

Utility::Utility(StudentManagement* s,CourseManagement* c,Registration* r,ReportGenerator* g,FileManagement* f) : stuMana(s),courMana(c),regist(r),repoGene(g),fileMana(f) {}

Utility::~Utility() {}

void Utility::mainMenu(){
    system("clear");
	printf("HKUST Course Registration System\n");
	printf("--------------------------------\n");
	printf("\n");
	printf("1. Student Management\n");
	printf("2. Course Management\n");
	printf("3. Course Registration\n");
	printf("4. Report Management\n");
	printf("5. File Management\n");
	printf("6. Exit\n");
	printf("\n");

	int choice = getChoice(MAINMENU_SIZE);

	switch(choice){
        case 1: { studentMenu(); break;}
		case 2: { courseMenu(); break; }
		case 3: { registrationMenu(); break;}
		case 4: { reportMenu(); break;}
		case 5: { fileMenu(); break;}
        default:{ break;}
	}
}

void Utility::studentMenu(){
    system("clear");
	printf("HKUST Course Registration System (Student Menu)\n");
	printf("------------------------------------------------\n");
	printf("\n");
	printf("1. Insert Student Record\n");
	printf("2. Modify Student Record\n");
	printf("3. Delete Student Record\n");
	printf("4. Query Student Record\n");
	printf("5. Go back to main menu\n");
	printf("\n");

	int choice = getChoice(STUDENTMENU_SIZE);
    
	switch(choice){
        case 1: {
            printf("Enter the student ID: ");
            string key = getId();
            stuMana->Insert(key);
            readEnter();
            break;}
        case 2: {
            printf("Enter the student ID: ");
            string key = getId();
            stuMana->Modify(key);
            readEnter();
            break;}
        case 3: {
            printf("Enter the student ID: ");
            string key = getId();
            regist->deleteStudent(key);
            stuMana->Delete(key);
            readEnter();
            break;}
        case 4: {
            printf("Enter the student ID: ");
            string key = getId();
            stuMana->Query(key);
            readEnter();
            break;}
		case 5: { mainMenu(); break;}
        default:{ break;}
	}
}

void Utility::courseMenu(){
    system("clear");
	printf("HKUST Course Registration System (Course Menu)\n");
	printf("-----------------------------------------------\n");
	printf("\n");
	printf("1. Insert Course Record\n");
	printf("2. Modify Course Record\n");
	printf("3. Delete Course Record\n");
	printf("4. Query Course Record\n");
	printf("5. Go back to main menu\n");
	printf("\n");

	int choice = getChoice(COURSEMENU_SIZE);
    
	switch(choice){
        case 1: {
            printf("Enter the course code: ");
            string key = getCode();
            courMana->Insert(key);
            readEnter();
            break;}
		case 2: {
            printf("Enter the course code: ");
            string key = getCode();
            courMana->Modify(key);
            readEnter();
            break;}
        case 3: {
            printf("Enter the course code: ");
            string key = getCode();
            if(regist->emptyCourse(key)){ courMana->Delete(key);}
            else{ printf("Some students already registered in this course, deletion fail");}
            readEnter();
            break;}
        case 4: {
            printf("Enter the course code: ");
            string key = getCode();
            courMana->Query(key);
            readEnter();
            break;}
		case 5: { mainMenu(); break;}
        default:{ break;}
	}
}

void Utility::registrationMenu(){
    system("clear");
	printf("HKUST Course Registration System (Registration Menu)\n");
	printf("-----------------------------------------------------\n");
	printf("\n");
	printf("1. Add Course\n");
	printf("2. Drop Course\n");
	printf("3. Modify Exam Mark\n");
	printf("4. Query Registration\n");
	printf("5. Go back to main menu\n");
	printf("\n");

	int choice = getChoice(REGISTRATIONMENU_SIZE);
	switch(choice){
		case 1: { regist->Add(); readEnter(); break;}
		case 2: { regist->Drop(); readEnter(); break;}
		case 3: { regist->Modify(); readEnter(); break;}
		case 4: { regist->Query();  readEnter(); break;}
		case 5: { mainMenu(); break;}
        default:{ break;}
	}
}

void Utility::reportMenu(){
    system("clear");
	printf("HKUST Course Registration System (Reprot Generation Menu)\n");
	printf("----------------------------------------------------------\n");
	printf("\n");
	printf("1. List all student information\n");
	printf("2. List all course information\n");
	printf("3. List all courses of a student\n");
	printf("4. List all students of a course\n");
	printf("5. Go back to main menu\n");
	printf("\n");

	int choice = getChoice(REPORTMENU_SIZE);
	switch(choice){
		case 1: { repoGene->Students(); readEnter(); break;}
		case 2: { repoGene->Courses(); readEnter(); break;}
		case 3: { repoGene->StudentRegs(); readEnter(); break;}
		case 4: { repoGene->CourseRegs(); readEnter(); break;}
		case 5: { mainMenu(); break;}
        default:{ break;}
	}
}

void Utility::fileMenu(){
    system("clear");
	printf("HKUST Course Registration System (File Menu)\n");
	printf("---------------------------------------------\n");
	printf("\n");
	printf("1. Save Database\n");
	printf("2. Load Database\n");
	printf("3. Go back to main menu\n");
	printf("\n");

	int choice = getChoice(FILEMENU_SIZE);
	switch(choice){
		case 1: { fileMana->Save(); readEnter(); break;}
		case 2: { fileMana->Load(); readEnter(); break;}
		case 3: { mainMenu(); break;}
        default:{ break;}
	}
}

bool Utility::validChoice(const string &c,int s){
    if(c.length()!=1 || !isdigit(c[0]))
        return false;
    int choice = atoi(c.c_str());
    if(choice>s||choice<1)
        return false;
    return true;
}

int Utility::getChoice(int size){
    printf("Enter your choice (1-%d): ",size);
    string choice;
    getline(cin,choice);
    while(!validChoice(choice,size)){
        printf("Invalid input, re-enter again (1-%d): ",size);
        getline(cin,choice);
    }
    return atoi(choice.c_str());
}

bool Utility::isNum(const string &s){
    for(int i=0;i<s.length();i++){
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}
string Utility::getId(){
    string key = "00000000";
    getline(cin,key);
    while(key.length()!=8||!isNum(key)){
        printf("Invalid input, re-enter again [student ID]: ");
        getline(cin,key);
    }
    return key;
}

bool Utility::validCode(const string &s){
    if(s.length()!=7&&s.length()!=8)
        return false;
    for(int i=0;i<4;i++){
        if(!isupper(s[i]))
            return false;
    }
    for(int i=4;i<s.length();i++){
        if(!isdigit(s[i])&&!isupper(s[i]))
            return false;
    }
    return true;
}

string Utility::getCode(){
    string key = "XXXX0000";
    getline(cin,key);
    while(!validCode(key)){
        printf("Invalid input, re-enter again [course code]: ");
        getline(cin,key);
    }
    return key;
}

void Utility::readEnter(){
    printf("\n\nHit ENTER to continue...\n");
    string read;
    getline(cin,read);
    mainMenu();
}

#endif /*UTILITY_H*/
