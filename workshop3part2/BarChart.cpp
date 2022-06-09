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
#include "BarChart.h"

using namespace std;
namespace sdds {
	void BarChart::init(const char* title, int noOfSampels, char fill)
	{
		m_chart_title = new char[strlen(title) + 1];
		strcpy(m_chart_title, title);
		m_bars = new Bar[noOfSampels];
		m_no_of_bars = noOfSampels;
		m_bar_fill = fill;
		m_added_bars = 0;
	}

	void BarChart::add(const char* bar_title, int value)
	{
		m_bars[m_added_bars].set(bar_title, m_bar_fill, value);
		m_added_bars++;
	}

	void BarChart::draw() const
	{
		if (m_added_bars == m_no_of_bars) {
			cout << m_chart_title << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			for (int i = 0; i < m_no_of_bars; i++) {
				m_bars[i].draw();
			}
			cout << "-----------------------------------------------------------------------" << endl;
		}
		else {
			cout << "Invalid Chart!" << endl;
		}
	}

	void BarChart::deallocate()
	{
		delete[] m_chart_title;
		delete[] m_bars;
	}

}