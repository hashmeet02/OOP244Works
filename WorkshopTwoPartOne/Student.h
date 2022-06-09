//***************************************************
//                    W2P1
//Hashmeet Singh Saini
//153070214
//hsaini28@myseneca.ca
//OOP244 - NFF
//I have done all the coding by myself and only copied 
//the code that my professor provided to complete my 
//workshops and assignments.
//***************************************************

#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "File.h"

namespace sdds {
    struct Student {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };
    void sort();
    bool load(Student& stu);
    bool load(const char *datafile);
    void display(const Student& stu);
    void display();
    void deallocateMemory();

    extern Student* students;

}
#endif // !SDDS_STUDENT_H_