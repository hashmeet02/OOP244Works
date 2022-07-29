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
#include "Name.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	Name::Name()
	{
		m_value = nullptr;
	}

	Name::Name(const char* name)
	{
		m_value = nullptr;
		if (name != nullptr) {
			m_value = U.aloCpy(name);
		}
	}

	Name::Name(const Name& toCopy)
	{
		m_value = nullptr;
		*this = toCopy;
	}

	Name& Name::operator=(const Name& toAssign)
	{
		if (this != &toAssign) {
			delete[] m_value;
			m_value = nullptr;
			m_value = U.aloCpy(toAssign.m_value);
		}
		return *this;
	}

	Name::~Name()
	{
		delete[] m_value;
		m_value = nullptr;
	}

	Name::operator const char* () const
	{
		return m_value;
	}

	Name::operator bool() const
	{
		return !(m_value == nullptr);
	}

	std::ostream& Name::display(std::ostream& ostr) const
	{
		if (this->operator bool()) {
			ostr << m_value;
		}
		return ostr;
	}

	std::istream& Name::read(std::istream& istr)
	{
		char value[100];
		istr.get(value, 100, ' ');
		m_value = U.aloCpy(value);
		if (!cin.fail()) {
			istr.ignore(1,'\n');
		}
		return istr;
	}


	std::ostream& operator<<(std::ostream& os, const Name& RO)
	{
		return RO.display(os);
	}

	std::istream& operator>>(std::istream& is, Name& RO)
	{
		return RO.read(is);
	}

}

