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
#include "MemberParliament.h"

using namespace std;
namespace sdds {
	MemberParliament::MemberParliament(const char* parliamentId, int age)
	{
		U.strcpy(m_parliamentId , parliamentId);
		U.strcpy(m_district , "Unassigned");
		m_age = age;
	}
	void MemberParliament::NewDistrict(const char* district)
	{
		cout << "|";
		cout.width(8);
		cout << m_parliamentId << "| |";
		cout.width(20);
		cout << m_district << " ---> ";
		U.strcpy(m_district, district);
		cout.setf(ios::left);
		cout.width(23);
		cout << m_district << "|" << endl;
		cout.unsetf(ios::left);
	}
	ostream& MemberParliament::write(ostream& os) const{
		os << "| " << m_parliamentId << " | " << m_age << " | " << m_district;
		return os;
	}
	istream& MemberParliament::read(istream& in) {
		cout << "Age: ";
		in >> m_age;
		cout << "Id: ";
		in >> m_parliamentId;
		cout << "District: ";
		in >> m_district;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const MemberParliament& RO)
	{
		return RO.write(os);
	}

	std::istream& operator>>(std::istream& is, MemberParliament& RO)
	{
		return RO.read(is);
	}

}