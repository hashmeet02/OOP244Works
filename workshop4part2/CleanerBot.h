//*******************************************************************
//Reflection Workshop 4 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : June 07, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_CLEANERBOT_H
#define SDDS_CLEANERBOT_H

namespace sdds {

	class CleanerBot {
		char* m_location;
		double m_battery;
		int m_brush;
		bool m_active;


	public:
		CleanerBot();

		CleanerBot(const char* location,
			double battery,
			int brush,
			bool active);

		~CleanerBot();


		CleanerBot& set(const char* location,
			double battery,
			int brush,
			bool active);
		CleanerBot& setLocation(const char* location);
		CleanerBot& setActive(bool active);
		CleanerBot& resetInfo();
		CleanerBot& deallocate();

		const char* getLocation()const;
		const double getBattery()const;
		const int getBrush()const;
		const bool isActive()const;
		const bool isValid()const;
		const CleanerBot& display()const;

	};

	int report(CleanerBot* bot, const short num_bots);
	void sort(CleanerBot* bot, const short num_bots);
}
#endif // !SDDS_CLEANERBOT_H
