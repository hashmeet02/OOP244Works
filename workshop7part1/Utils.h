/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version 1.0
// Date July 10th 2022
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
// Date : July 10, 2022
//
// I have done all the coding by myselfand only copied the code
// that my professor provided to complete my project milestones.
// ------------------------------------------------------------
/////////////////////////////////////////////////////////////////
***********************************************************************/
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
