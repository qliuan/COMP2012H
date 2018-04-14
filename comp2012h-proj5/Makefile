CPP = g++

Register: main.o StudentManagement.o CourseManagement.o Registration.o ReportGenerator.o FileManagement.o 
	$(CPP) -o Register main.o StudentManagement.o CourseManagement.o Registration.o ReportGenerator.o FileManagement.o  
main.o: main.cpp StudentManagement.h CourseManagement.h Registration.h ReportGenerator.h FileManagement.h Utility.h 
	$(CPP) -c main.cpp
FileManagement.o: FileManagement.h FileManagement.cpp Registration.h CourseManagement.h StudentManagement.h HashTable.h List.h
	$(CPP) -c FileManagement.cpp
ReportGenerator.o: ReportGenerator.h ReportGenerator.cpp Registration.h CourseManagement.h StudentManagement.h HashTable.h List.h
	$(CPP) -c ReportGenerator.cpp
Registration.o: Registration.h Registration.cpp CourseManagement.h StudentManagement.h HashTable.h List.h
	$(CPP) -c Registration.cpp
CourseManagement.o: CourseManagement.h CourseManagement.cpp HashTable.h List.h
	$(CPP) -c CourseManagement.cpp
StudentManagement.o: StudentManagement.h StudentManagement.cpp HashTable.h List.h
	$(CPP) -c StudentManagement.cpp
clean: 
	rm -f *.o Register 
version:
	$(CPP) -v