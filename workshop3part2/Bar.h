//*******************************************************************
//Reflection Workshop 3 Part 2
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : June 02, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************
#ifndef SDDS_BAR_H
#define SDDS_BAR_H

namespace sdds{
	class Bar {
		char m_title[20]{};
		char m_fill;
		int m_sample_value{};
	public:
		void setEmpty();
		void set(const char* title, char fill, int value);
		bool isBarValid();
		void draw();
	};
}

#endif // !SDDS_BAR_H
