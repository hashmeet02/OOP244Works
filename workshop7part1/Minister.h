//*******************************************************************
//Reflection Workshop 7 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 12, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************
#ifndef SDDS_MINISTER_H_
#define SDDS_MINISTER_H_
#include <iostream>
#include "Utils.h"
#include "MemberParliament.h"
namespace sdds {
	const int MAX_MINISTER_NAME_LENGTH = 50;
	class Minister : public MemberParliament {
		char m_primeMinisterName[MAX_MINISTER_NAME_LENGTH];
		double m_yearAssumed;
	public:
		Minister(const char* parliamentId, int age, int yearAssumed, const char* primeMinisterName, const char* district);
		void changePM(const char* pm);
		void assumeOffice(double year);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Minister& RO);
	std::istream& operator>>(std::istream& is, Minister& RO);
}
#endif // !SDDS_MINISTER_H_