// Final Project Milestone 55
// Book Module
// File  Book.cpp
// Version 1.0
// Author  Hashmeet Singh Saini
// Revision History
// -----------------------------------------------------------
// Name                    Date                 Reason
// Hashmeet Singh Saini    July 25th            Preliminary
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
#include "Book.h"
#include "Utils.h"
#include "Lib.h"
using namespace std;
namespace sdds {
	Book::Book() {
		/*Publication();*/
		m_author = nullptr;
	}

	Book::Book(const Book& toCopy)
	{
		m_author = nullptr;
		*this = toCopy;
	}

	Book::~Book()
	{
		delete[] m_author;
		m_author = nullptr;
	}

	char Book::type() const
	{
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const
	{		
		Publication::write(os);
		if (Publication::conIO(os)) {
			char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };
			std::strncpy(author, m_author, SDDS_AUTHOR_WIDTH);
			os << " ";
			os.width(SDDS_AUTHOR_WIDTH);
			os.setf(ios::left);
			os.fill(' ');
			os << author << " |";
			os.unsetf(ios::left);
		}
		else {
			os << "\t" << m_author;
		}
		return os;
	}

	std::istream& Book::read(std::istream& istr)
	{
		char author[250]={0};
		Publication::read(istr);
		if (m_author && m_author[0]) {
			delete m_author;
			m_author = nullptr;
		}
		if (conIO(istr)) {
			istr.ignore();
			cout << "Author: ";
		}
		else {
			istr.ignore(1000,'\t');
		}

		istr.get(author, 256);

		if (!cin.fail()) {
			m_author = U.aloCpy(author);
		}
		return istr;
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);
		resetDate();
	}

	Book::operator bool() const
	{
		bool flag = false;
		if ((m_author && m_author[0]) && (Publication::operator bool())) {
			flag = true;
		}
		return flag;
	}

	Book& Book::operator=(const Book& toAssing)
	{
		if (this != &toAssing) {
			Publication::operator=(toAssing);
			delete[] m_author;
			m_author = U.aloCpy(toAssing.m_author);
		}
		return *this;
	}


};