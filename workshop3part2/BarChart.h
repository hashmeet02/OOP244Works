//*******************************************************************
//Reflection Workshop 3 Part 2
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : June 02, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************
#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H

namespace sdds {
	class Bar;
	class BarChart {
		char* m_chart_title;
		Bar* m_bars;
		char m_bar_fill;
		int m_no_of_bars;
		int m_added_bars;
	public:
		/*bool areBarsValid();*/
		void init(const char* title, int noOfSampels, char fill);
		void add(const char* bar_title, int value);
		void draw()const;
		void deallocate();
	};
}

#endif // !SDDS_BAR_H
