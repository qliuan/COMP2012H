#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "List.h"
#include "HashTable.h"
#include "StudentManagement.h"
#include "CourseManagement.h"
#include <string>

struct Index;

struct Record{
	string stuId;
	string courCode;
	int mark = NULL;

	Record *prev;
	Record *next;
    
    Index *idIndex;
    Index *codeIndex;

	bool operator==(const Record& rec){
		for(int i=0;i<stuId.length();i++){
			if(stuId[i]!=rec.stuId[i])
                return false;
		}
		for(int i=0;i<courCode.length();i++){
			if(courCode[i]!=rec.courCode[i])
				return false;
		}
		return true;
	}
	bool operator<(const Record& rec){
		for(int i=0;i<stuId.length();i++){
			if(stuId[i]-'0'<rec.stuId[i]-'0')
				return true;
			if(stuId[i]-'0'>rec.stuId[i]-'0')
				return false;
		}
		for(int i=0;i<courCode.length();i++){
			int v1;
			int v2;
			if(isdigit(courCode[i]))
				v1 = courCode[i] - '0';
			else
				v1 = courCode[i] - 'A' + 10;
			if(isdigit(rec.courCode[i]))
				v2 = rec.courCode[i] - '0';
			else
				v2 = rec.courCode[i] - 'A' + 10;
			if(v1<v2)
                return true;
            if(v1>v2)
                return false;
		}
		return false;
	}
	bool operator>(const Record& rec){
		for(int i=0;i<stuId.length();i++){
			if(stuId[i]-'0'>rec.stuId[i]-'0')
				return true;
			if(stuId[i]-'0'<rec.stuId[i]-'0')
				return false;
		}
		for(int i=0;i<courCode.length();i++){
			int v1;
			int v2;
			if(isdigit(courCode[i]))
				v1 = courCode[i] - '0';
			else
				v1 = courCode[i] - 'A' + 10;
			if(isdigit(rec.courCode[i]))
				v2 = rec.courCode[i] - '0';
			else
				v2 = rec.courCode[i] - 'A' + 10;
			if(v1>v2)
                return true;
            if(v1<v2)
                return false;
		}
		return false;
	}
};

struct Index{
	string key;
	Record* rec = NULL;
    
    Index *prev;
    Index *next;

	bool operator==(const Index& in){
		for(int i=0;i<key.length();i++){
			if(key[i]!=in.key[i])
                return false;
		}
		
        if(in.rec == NULL)
            return false;
        return true;
	}
    bool operator==(const Index* in){
        for(int i=0;i<key.length();i++){
            if(key[i]!=in->key[i])
                return false;
        }
        return true;
    }
	bool operator<(const Index& in){
		for(int i=0;i<key.length();i++){
			int v1;
			int v2;
			if(isdigit(key[i]))
				v1 = key[i] - '0';
			else
				v1 = key[i] - 'A' + 10;
			if(isdigit(in.key[i]))
				v2 = in.key[i] - '0';
			else
				v2 = in.key[i] - 'A' + 10;
			if(v1<v2)
                return true;
            if(v1>v2)
                return false;
		}
			
		return false;
	}
	bool operator>(const Index& in){
		for(int i=0;i<key.length();i++){
			int v1;
			int v2;
			if(isdigit(key[i]))
				v1 = key[i] - '0';
			else
				v1 = key[i] - 'A' + 10;
			if(isdigit(in.key[i]))
				v2 = in.key[i] - '0';
			else
				v2 = in.key[i] - 'A' + 10;
			if(v1>v2)
                return true;
            if(v1<v2)
                return false;
		}
        
		return false;
	}
};

#define ID_BUCKETS 29
#define ID_BASE 10
#define CODE_BUCKETS 17
#define CODE_BASE 36
typedef HashTable<Index> IndexTable;
typedef List<Index> IndexList;

class Registration
{
private:
	Record *head;
	Record *end;
	Record *nextRecord;
	IndexTable *idTab;
	IndexTable *codeTab;
	StudentManagement *stuMana;
	CourseManagement *courMana;
public:
	Registration(StudentManagement*,CourseManagement*);
	~Registration();
	
	bool Add();
	bool Drop();
	bool Modify();
	bool Query();

	bool validId(const string&);
	string getId();
	bool validCode(const string&);
	string getCode();
	bool validMark(const string&);
	int getMark();

	Record* searchRecord(const string&,const string&);
	void deleteIndexes(Record*);
	bool deleteStudent(const string&);
	bool emptyCourse(const string&);
	Index* searchStudent(const string&);
	Index* searchCourse(const string&);
    
    bool Add(const string&,const string&,int);
    Record* getHead();
    Record* getEnd();
};


#endif /*REGISTRATION_H*/
