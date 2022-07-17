//*******************************************************************
//Reflection Workshop 7 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 12, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
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
#endif // !
