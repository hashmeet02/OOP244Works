//*******************************************************************
//Reflection Workshop 9 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 26, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>

namespace sdds {
    class Name {
        char* m_value;
    public:
        Name();
        Name(const char* name);
        // Rule of three goes here:
        Name(const Name& toCopy);
        Name& operator=(const Name& toAssign);
        ~Name();

        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);
    };
    std::ostream& operator<<(std::ostream& os, const Name& RO);
    std::istream& operator>>(std::istream& is, Name& RO);

}
#endif // !SDDS_NAME_H
