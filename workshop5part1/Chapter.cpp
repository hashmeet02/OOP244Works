//*******************************************************************
//Reflection Workshop 4 Part 2
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : June 15, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Chapter.h"

using namespace std;

namespace sdds {
	void Chapter::init_chapter() {
		m_title[0] = '\0';
		m_num_pages = 0;
		m_num_words = 0;
		m_chapter_number = 0;
	}
	Chapter::Chapter() {
		init_chapter();
	}

	Chapter::Chapter(const char* title_) {
		init_chapter();
		strcpy(m_title , title_);
	}
	Chapter::Chapter(const char* title_, int chapter_num,  int n_pages, int n_words) {
		strcpy(m_title, title_);
		m_chapter_number = chapter_num;
		m_num_pages = n_pages;
		m_num_words = n_words;
	}
	ostream& Chapter::display(std::ostream& os)const
	{
		cout.setf(std::ios::left);
		os << "| Chapter ";
		os.width(2);
		os << m_chapter_number +1<< " | ";
		os.width(MAX_CHAPTER_TITLE);
		os << m_title << " |" << endl;
		return os;
	}

	const int Chapter::getPages() const
	{
		return m_num_pages;
	}

	Chapter::operator int() const
	{
		return m_num_pages;
	}

	Chapter::operator double() const
	{
		return (double)m_num_words / m_num_pages;
	}

	Chapter::operator const char* () const
	{
		return m_title;
	}

	Chapter& Chapter::operator=(const Chapter& toCopy)
	{
		if (toCopy.m_title && toCopy.m_title[0]) {
			strcpy(this->m_title, toCopy.m_title);
			this->m_num_pages = toCopy.m_num_pages;
			this->m_num_words = toCopy.m_num_words;
			this->m_chapter_number = toCopy.m_chapter_number - 1;
		}
		return *this;
	}

	Chapter& Chapter::operator++()
	{
		m_num_pages += 1;
		return *this;
	}

	Chapter& Chapter::operator--()
	{
		m_num_pages -= 1;
		return *this;
	}

	
	ostream& operator<<(ostream& leftOper, Chapter& righOper)
	{
		righOper.display(leftOper);
		return leftOper;
	}

}

