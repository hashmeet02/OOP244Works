//*******************************************************************
//Reflection Workshop 3 Part 2
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : June 02, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include "Bar.h"
#include <iostream>
#include <string.h>

using namespace std;
namespace sdds {
	void Bar::setEmpty()
	{
		strcpy(m_title, "");
		m_sample_value=-1;

	}
	void Bar::set(const char* title,char fill, int value)
	{
		strcpy(m_title, title);
		m_fill = fill;
		if (value >= 0 && value <= 100) {
			m_sample_value = value;
		}
		else
		{
			setEmpty();
		}
	}
	bool Bar::isBarValid()
	{
		if (m_sample_value >= 0 && m_sample_value <= 100) return true;
		else return false;
	}
	void Bar::draw() {
		if (isBarValid()) {
			cout.width(20);
			cout.setf(ios::left);
			cout.fill('.');
			cout << m_title << "|";
			for (int i = 0; i < m_sample_value / 2; i++) {
				cout << m_fill;
			}
			cout << endl;
		}
	}

}

