#include "StudentManagement.h"
#include "CourseManagement.h"
#include "Registration.h"
#include "ReportGenerator.h"
#include "FileManagement.h"
#include "Utility.h"

int main(){
    StudentManagement* stuMana = new StudentManagement();
    CourseManagement* courMana = new CourseManagement();
    Registration* regist = new Registration(stuMana,courMana);
    ReportGenerator* repoGene = new ReportGenerator(stuMana,courMana,regist);
    FileManagement* fileMana = new FileManagement(stuMana,courMana,regist);
    Utility* uti = new Utility(stuMana,courMana,regist,repoGene,fileMana);
    
    uti->mainMenu();
    
    return 0;
}
