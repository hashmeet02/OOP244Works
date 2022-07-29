//*******************************************************************
//Reflection Workshop 9 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 26, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include "FullName.h"
#include "Name.h"


using namespace std;
namespace sdds {
	FullName::FullName()
	{
		FullName::m_value = nullptr;
	}

	FullName::FullName(const char* name, const char* lastName) : Name( name )
	{
		FullName::m_value = U.aloCpy(lastName);
	}

	FullName::FullName(const FullName& toCopy)
	{
		FullName::m_value = nullptr;
		*this = toCopy;
	}

	FullName& FullName::operator=(const FullName& toAssign)
	{
		if (this != &toAssign) {
			delete[] FullName::m_value;
			FullName::m_value = nullptr;
			Name::operator=(toAssign);  
			FullName::m_value = U.aloCpy(toAssign.m_value);			
		}
		return *this;
	}

	FullName::~FullName()
	{
		//~Name();
		delete[] FullName::m_value;
		FullName::m_value = nullptr;		
	}

	FullName::operator const char* () const
	{
		return FullName::m_value;
	}
	FullName::operator bool() const
	{
		return (FullName::m_value && FullName::m_value[0]) && (Name::operator bool());
	}
	std::ostream& FullName::display(std::ostream& ostr) const
	{
		if (bool(this)) {
			ostr << Name::operator const char* () << " " << operator const char* ();
		}
		return ostr;
	}
	std::istream& FullName::read(std::istream& istr)
	{
		Name::read(istr);
		char value[100];
		istr.getline(value, 100, '\n');
		m_value=U.aloCpy(value);
		return istr;
	}

}