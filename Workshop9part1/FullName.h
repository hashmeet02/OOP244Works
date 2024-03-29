//*******************************************************************
//Reflection Workshop 9 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 26, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#ifndef SDDS_FULLNAME_H
#define SDDS_FULLNAME_H
#include <iostream>
#include "Name.h"
#include "Utils.h"

namespace sdds {
    class FullName : public Name {
        char* m_value;
    public:
        FullName();
        FullName(const char* name, const char* lastName);
        // Rule of three goes here:
        FullName(const FullName& toCopy);
        FullName& operator=(const FullName& toAssign);
        ~FullName();

        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);
    };

}
#endif // !SDDS_FULLNAME_H
