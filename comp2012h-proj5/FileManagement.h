#ifndef FileManagement_h
#define FileManagement_h

#include "StudentManagement.h"
#include "CourseManagement.h"
#include "Registration.h"

class FileManagement {
private:
    StudentManagement* stuMana;
    CourseManagement* courMana;
    Registration* regist;
    
public:
    FileManagement(StudentManagement*,CourseManagement*,Registration*);
    ~FileManagement();
    bool Load();
    bool Save();
    bool checkStudent(const string&);
    bool checkCourse(const string&);
    bool checkRegistration(const string&);
};

#endif /* FileManagement_h */
