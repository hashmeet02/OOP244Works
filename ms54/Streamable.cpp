// Final Project Milestone 54
// Streamable Module
// File  Streamable.h
// Version 1.0
// Author  Hashmeet Singh Saini
// Revision History
// -----------------------------------------------------------
// Name                    Date                 Reason
// Hashmeet Singh Saini    July 23rd            Preliminary
// -----------------------------------------------------------
// Name:			Hashmeet Singh Saini
// Seneca ID : hsaini28
// Student No. : 153070214
// Date : July 30th, 2022
// 
// I have done all the coding by myselfand only copied the code
// that my professor provided to complete my project milestones.
// ------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Streamable.h"
namespace sdds {
    std::ostream& operator<<(std::ostream& os, const Streamable& RO) {
        if (RO) {
            RO.write(os);
        }
        return os;
    }
    std::istream& operator>>(std::istream& is, Streamable& RO) {
        return RO.read(is);
    }

}