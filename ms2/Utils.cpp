/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version 1.0
// Date July 14th 2022
// Author Hashmeet Singh Saini
// Description Utility module for extra basic features to be used in the project
//
// Revision History
// -----------------------------------------------------------
// Name                    Date            Reason
// Hashmeet Singh Saini    July 10th       Preliminary
// -----------------------------------------------------------
// Name:			Hashmeet Singh Saini
// Seneca ID : hsaini28
// Student No. : 153070214
// Date : July 14, 2022
//
// I have done all the coding by myselfand only copied the code
// that my professor provided to complete my project milestones.
// ------------------------------------------------------------
/////////////////////////////////////////////////////////////////
***********************************************************************/

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