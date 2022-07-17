//*******************************************************************
//Reflection Workshop 7 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 12, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Minister.h"

using namespace std;
namespace sdds {
	Minister::Minister(const char* parliamentId, int age, int yearAssumed, const char* primeMinisterName, const char* district):MemberParliament{parliamentId, age}
	{
		MemberParliament::NewDistrict(district);
		m_yearAssumed = yearAssumed;
		U.strcpy(m_primeMinisterName, primeMinisterName);
	}
	void Minister::changePM(const char* pm)
	{
		U.strcpy(m_primeMinisterName, pm);
	}

	void Minister::assumeOffice(double year)
	{
		m_yearAssumed = year;
	}

	std::istream& Minister::read(std::istream& in)
	{
		MemberParliament::read(in);
		cout << "Reports TO: ";
		in >> m_primeMinisterName;
		cout << "Year Assumed Office: ";
		in >> m_yearAssumed;
		return in;
	}

	std::ostream& Minister::write(std::ostream& os) const
	{
		MemberParliament::write(os);
		os << " | " << m_primeMinisterName << "/" << m_yearAssumed;
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Minister& RO)
	{
		return RO.write(os);
	}

	std::istream& operator>>(std::istream& is, Minister& RO)
	{
		return RO.read(is);
	}

}