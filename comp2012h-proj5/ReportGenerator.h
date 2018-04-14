#ifndef ReportGenerator_h
#define ReportGenerator_h

#include "List.h"
#include "HashTable.h"
#include "StudentManagement.h"
#include "CourseManagement.h"
#include "Registration.h"
#include <string>

class ReportGenerator {
private:
    StudentManagement* stuMana;
    CourseManagement* courMana;
    Registration* regist;
public:
    ReportGenerator(StudentManagement*,CourseManagement*,Registration*);
    ~ReportGenerator();
    
    bool Students();
    bool Courses();
    bool StudentRegs();
    bool CourseRegs();
    
    bool validId(const string&);
    string getId();
    bool validCode(const string&);
    string getCode();
};

#endif /* ReportGenerator_h */
