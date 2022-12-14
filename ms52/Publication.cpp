// Final Project Milestone 52
// Publication Module
// File  Publication.cpp
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
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Streamable.h"
#include "Publication.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	Publication::Publication()
	{
		setDefault();
	}

	void Publication::setDefault()
	{
		m_title = nullptr;
		U.strcpy(m_shelfld, "");
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();
	}

	void Publication::set(int member_id)
	{
		m_membership = member_id;
	}

	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	void Publication::resetDate()
	{
		m_date.setToToday();
	}

	char Publication::type() const
	{
		return 'P';
	}

	bool Publication::onLoan() const
	{
		bool checkedOut = false;
		if (m_membership != 0) {
			checkedOut = true;
		}
		return checkedOut;
	}

	Date Publication::checkoutDate() const
	{
		return m_date;
	}

	bool Publication::operator==(const char* title) const
	{
		bool found = false;
		if (strstr(m_title, title)) {
			found = true;
		}
		return found;
	}

	Publication::operator const char* () const
	{
		return m_title;
	}

	int Publication::getRef() const
	{
		return m_libRef;
	}

	bool Publication::conIO(ios& io) const
	{
		bool flag = false;
		if ((&io == &cin) || (&io == &cout)) {
			flag = true;
		}
		return flag;
	}

	ostream& Publication::write(ostream& os) const
	{
		char title[SDDS_TITLE_WIDTH + 1] = { 0 };
		std::strncpy(title, m_title, SDDS_TITLE_WIDTH);

		if (conIO(os)) {
			os << "| ";
			os.width(SDDS_SHELF_ID_LEN);
			os << m_shelfld << " | ";
			os.width(SDDS_TITLE_WIDTH);
			os.setf(ios::left);
			os.fill('.');
			os << title << " | ";
			os.unsetf(ios::left);
			os.fill(' ');
			if (onLoan()) {
				os << m_membership << " | ";
			}
			else {
				os << " N/A  | ";
			}
			os << m_date << " |";
		}
		else {
			os << type() << "\t" << m_libRef << "\t" << m_shelfld << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
		}
		return os;
	}

	istream& Publication::read(istream& istr)
	{
		char shelfld[50]{};
		char title[99];
		Date date;
		int libRef;
		int membership;
		setDefault();
		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr >> shelfld;
			if (strlen(shelfld) != SDDS_SHELF_ID_LEN) {
				istr.setstate(ios::failbit);
			}
			cout << "Title: ";
			if (!cin.fail()) {
				istr.ignore(1000, '\n');
				istr.getline(title,256);
			}
			
			cout << "Date: ";
			if (!cin.fail()) {
				istr >> date;
				if (date.errCode()) {
					istr.setstate(ios::failbit);
				}
			}
			if (!cin.fail()) {
				m_title = U.aloCpy(title);
				m_date = date;
				U.strcpy(m_shelfld, shelfld);
			}

		}
		else {
			istr >> libRef;
			istr.ignore(1, '\n');
			istr >> shelfld;
			istr.ignore(1, '\n');
			istr.getline(title, 99,'\t');
			istr >> membership;
			istr.ignore(1, '\n');
			istr >> date;

			m_libRef = libRef;
			m_title = U.aloCpy(title);
			U.strcpy(m_shelfld, shelfld);
			m_membership = membership;
			m_date = date;
			if (date.errCode()) istr.setstate(std::ios_base::failbit);
		}
		return istr;
	}

	Publication::operator bool() const
	{
		bool flag = false;
		if ((m_title && m_title[0]) && (m_shelfld && m_shelfld[0])) {
			flag = true;
		}
		return flag;
	}

	Publication::~Publication()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	Publication::Publication(const Publication& toCopy)
	{
		setDefault();
		*this = toCopy;
	}

	Publication& Publication::operator=(const Publication& toAssing)
	{
		if (this != &toAssing) {
			delete[] m_title;
			U.strcpy(m_shelfld, toAssing.m_shelfld);
			m_membership = toAssing.m_membership;
			m_libRef = toAssing.m_libRef;
			m_date = toAssing.m_date;
			m_title = U.aloCpy(toAssing.m_title);
		}
		return *this;
	}




}