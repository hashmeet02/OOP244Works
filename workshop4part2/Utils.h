//*******************************************************************
//Reflection Workshop 4 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : June 07, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#define DEBUG
#include <iostream>
namespace sdds {
    class Utils {
    public:
        int strlen(const char* str);
        void strcpy(char* des, const char* src);
        char* aloCpy(const char* src);
    };
    extern Utils U;
}
#endif // !SDDS_UTILS_H