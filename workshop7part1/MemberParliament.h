//*******************************************************************
//Reflection Workshop 7 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 12, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#ifndef SDDS_MEMBERPARLIAMENT_H_
#define SDDS_MEMBERPARLIAMENT_H_
#include <iostream>
#include "Utils.h"
namespace sdds {
	const int MAX_ID_LENGTH = 32;
	const int MAX_DISTRICT_LENGTH = 64;
	class MemberParliament {
		char m_parliamentId[MAX_ID_LENGTH]{};
		char m_district[MAX_ID_LENGTH]{};
		int m_age;
	public:
		MemberParliament(const char* parliamentId, int age);
		void NewDistrict(const char* district);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const MemberParliament& RO);
	std::istream& operator>>(std::istream& is, MemberParliament& RO);
}
#endif // !SDDS_MEMBERPARLIAMENT_H_
