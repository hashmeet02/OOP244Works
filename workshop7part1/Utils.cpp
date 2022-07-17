//*******************************************************************
//Reflection Workshop 7 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 12, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************
#include <iostream>
using namespace std;
#include "Utils.h"
namespace sdds {
    Utils U;
    int Utils::strlen(const char* str)
    {
        int len = 0;
        while (str[len]) {
            len++;
        }
        return len;
    }
    void Utils::strcpy(char* des, const char* src) {
        int i;
        for (i = 0; src[i]; i++) {
            des[i] = src[i];
        }
        des[i] = 0;
    }
    char* Utils::aloCpy(const char* src)
    {
        char* value{};
        if (src) {
            value = new char[U.strlen(src) + 1];
            if (value) U.strcpy(value, src);
        }
        return value;
    }
}