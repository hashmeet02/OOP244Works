#include <iostream>
#include <cstring>
#include "CleanerBot.h"
#include "Utils.h"


using namespace std;
namespace sdds {

	CleanerBot::CleanerBot() {
		resetInfo();
	}

	CleanerBot::CleanerBot(const char* location,
		double battery,
		int brush,
		bool active) {
		resetInfo();
		set(location, battery, brush, active);
	}

	CleanerBot::~CleanerBot() {
		deallocate();
	}

	CleanerBot& CleanerBot::resetInfo() {
		m_location = nullptr;
		m_battery = 0;
		m_brush = 0;
		m_active = 0;
		return *this;
	}

	CleanerBot& CleanerBot::deallocate()
	{
		/*delete[] m_location;*/
		m_location = nullptr;
		return *this;
	}

	CleanerBot& CleanerBot::set(const char* location,
		double battery,
		int brush,
		bool active) {

		resetInfo();
		if ((location && location[0]) && battery > 0) {
			setLocation(location);
			m_battery = battery;
			m_brush = brush;
			setActive(active);
		}
		return *this;
	}

	CleanerBot& CleanerBot::setLocation(const char* location) {
		deallocate();
		m_location = U.aloCpy(location);
		return *this;
	};

	CleanerBot& CleanerBot::setActive(bool active) {

		m_active = active;
		return *this;
	}


	const char* CleanerBot::getLocation() const
	{
		return m_location;
	}

	const double CleanerBot::getBattery() const
	{
		return m_battery;
	}

	const int CleanerBot::getBrush() const
	{
		return m_brush;
	}

	const bool CleanerBot::isActive() const
	{
		return m_active;
	}

	const bool CleanerBot::isValid() const
	{
		return m_location && m_location[0];
	}

	const CleanerBot& CleanerBot::display() const {
		cout << "| ";
		cout.setf(ios::left);
		cout.width(11);
		cout << getLocation() << "| ";
		cout.unsetf(ios::left);

		cout.setf(ios::right);
		cout.width(7);
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << getBattery() << " | ";
		cout.unsetf(ios::fixed);


		cout.setf(ios::right);
		cout.width(18);
		cout << getBrush() << " | ";
		cout.unsetf(ios::right);

		cout.width(7);
		cout.setf(ios::left);
		if (isActive()) {
			cout << "YES" << "|";
		}
		else {
			cout << "NO" << "|";
		}
		cout.unsetf(ios::left);
		cout << endl;
		return *this;
	}

	int report(CleanerBot* bot, const short num_bots) {

		int lowBatCounter = 0;
		cout << "         ------ Cleaner Bots Report -----" << endl;
		cout << "     ---------------------------------------" << endl;
		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
		cout << "|------------+---------+--------------------+--------|" << endl;
		for (int i = 0; i < num_bots; i++) {
			if (bot[i].isValid()) {
				bot[i].display();
				if (bot[i].getBattery() < 30) {
					lowBatCounter++;
				}
			}

		}
		cout << endl;
		cout << "|====================================================|" << endl;
		cout << "| LOW BATTERY WARNING:                               |" << endl;
		cout << "|====================================================|" << endl;
		cout << "| Number of robots to be charged: ";
		cout.width(19);
		cout.setf(ios::left);
		cout << lowBatCounter<< "|" <<endl;
		cout << "| Sorting robots based on their available power:     |" << endl;
		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
		cout << "|------------+---------+--------------------+--------|" << endl;
		sort(bot, num_bots);
		for (int i = 0; i < num_bots; i++) {
			if (bot[i].isValid()) {
				bot[i].display();
				if (bot[i].getBattery() < 30) {
					lowBatCounter++;
				}
			}
		}
		cout << "|====================================================|" << endl;

		return 1;
	}

	void sort(CleanerBot* bot, const short num_bots) {
		int i, j;
		CleanerBot temp;
		for (i = num_bots - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				//if (bot[j].isValid() && bot[j + 1].isValid()) {
					if (bot[j].getBattery() < bot[j + 1].getBattery()) {
						temp = bot[j];
						bot[j] = bot[j + 1];
						bot[j + 1] = temp;
					}
				//}
			}
		}
	}

}

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<cstring>
//#include "Utils.h"
//#include "CleanerBot.h"
//
//using namespace std;
//namespace sdds {
//	CleanerBot::CleanerBot() {
//		resetInfo();
//	}
//
//	CleanerBot::CleanerBot(const char* location,
//		double battery,
//		int brush,
//		bool active) {
//
//		resetInfo();
//		CleanerBot::set(location, battery, brush, active);
//	}
//
//	CleanerBot::~CleanerBot() {
//		resetInfo();
//	}
//
//	CleanerBot& CleanerBot::resetInfo() {
//		m_location = nullptr;
//		m_battery = 0;
//		m_brush = 0;
//		m_active = 0;
//		return *this;
//	}
//
//	//CleanerBot& CleanerBot::deallocate()
//	//{
//	//	delete[] m_location;
//	//	m_location = nullptr;
//	//	return *this;
//	//}
//
//	CleanerBot& CleanerBot::set(const char* location,
//		double battery,
//		int brush,
//		bool active) {
//		resetInfo();
//		if ((location && location[0]) && (battery > 0) && (brush > 0)) {
//			CleanerBot::setLocation(location);
//			m_battery = battery;
//			m_brush = brush;
//			CleanerBot::setActive(active);
//		}
//		return *this;
//	}
//
//	CleanerBot& CleanerBot::setLocation(const char* location)
//	{
//		if (location && location[0]) {
//			/*deallocate();*/
//			delete[] m_location;
//			m_location = nullptr;
//			int locationLength = strlen(location);
//			m_location = new char[locationLength + 1];
//			strcpy(m_location, location);
//			/*m_location = U.aloCpy(location);*/
//		}
//		
//		return *this;
//	}
//
//	CleanerBot& CleanerBot::setActive(bool active)
//	{
//		m_active = active;
//		return *this;
//	}
//
//	const char* CleanerBot::getLocation() const
//	{
//		return m_location;
//	}
//
//	const double CleanerBot::getBattery() const
//	{
//		return m_battery;
//	}
//
//	const int CleanerBot::getBrush() const
//	{
//		return m_brush;
//	}
//
//	const bool CleanerBot::isActive() const
//	{
//		return m_active;
//	}
//
//	const bool CleanerBot::isValid() const
//	{
//		return m_location && m_location[0];
//		//if (m_location && m_location[0]) {
//		//	return true;
//		//}
//	}
//	const CleanerBot& CleanerBot::display() const {
//
//		cout << "| ";
//		cout.setf(ios::left);
//		cout.width(13);
//		cout << getLocation();
//
//		cout << " | ";
//		cout.unsetf(ios::left);
//		cout.width(7);
//		cout << getBattery();
//
//		cout << " | ";
//		cout.width(15);
//		cout << getBrush();
//
//		cout << " | ";
//		cout.setf(ios::left);
//		cout.width(6);
//		cout << (isActive() ? "YES" : "NO") << " |" << endl;
//
//		return *this;
//	}
//
//	//const CleanerBot& CleanerBot::display() const{
//	//	cout << "|";
//	//	cout << "Location: " << getLocation();
//	//	cout<< endl;
//	//	cout << "Battery: " << getBattery() << endl;
//	//	cout << "Brush: " << getBrush() << endl;
//	//	cout << "Active: " << isActive() << endl;
//	//	return *this;
//	//	//cout << "| ";
//	//	//cout.setf(ios::left);
//	//	//cout.width(14);
//	//	//cout << getLocation() << "| ";
//	//	//cout.width(10);
//	//	//cout.setf(ios::fixed);
//	//	//cout.precision(1);
//	//	//cout << getBattery() << "| ";
//	//	//cout.unsetf(ios::fixed);
//	//	//cout.unsetf(ios::left);
//	//	//cout.setf(ios::right);
//	//	//cout.width(14);
//	//	//cout << getBrush() << "| ";
//	//	//cout.width(9);
//	//	//if (getBrush()) {
//	//	//	cout << "YES" << "| ";
//	//	//}
//	//	//else {
//	//	//	cout << "NO" << "| ";
//	//	//}
//	//	//cout << endl;
//	//}
//
//	int report(CleanerBot* bot, const short num_bots)
//	{
//		int lowBatCounter = 0;
//		cout << "         ------ Cleaner Bots Report -----" << endl;
//		cout << "     ---------------------------------------" << endl;
//		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
//		cout << "|------------+---------+--------------------+--------|" << endl;
//		for (int i = 0; i < num_bots; i++) {
//			bot[i].display();
//			if (bot[i].getBattery() < 30) {
//				lowBatCounter++;
//			}
//		}
//		cout << endl;
//		cout << "|====================================================|" << endl;
//		cout << "| LOW BATTERY WARNING:                               |" << endl;
//		cout << "|====================================================|" << endl;
//
//		cout << "| Number of robots to be charged: ";
//		cout.width(49);
//		cout.setf(ios::left);
//		cout << lowBatCounter << endl;
//		cout << "| Sorting robots based on their available power:     |" << endl;
//		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
//		cout << "|------------+---------+--------------------+--------|" << endl;
//		sort(bot, num_bots);
//		for (int i = 0; i < num_bots; i++) {
//			bot[i].display();
//			if (bot[i].getBattery() < 30) {
//				lowBatCounter++;
//			}
//		}
//		cout << "|====================================================|" << endl;
//
//		return 0;
//	}
//
//	void sort(CleanerBot* bot, const short num_bots) {
//		int i, j;
//		CleanerBot temp;
//		for (i = num_bots - 1; i > 0; i--) {
//			for (j = 0; j < i; j++) {
//				if (bot[j].getBattery() > bot[j + 1].getBattery()) {
//					temp = bot[j];
//					bot[j] = bot[j + 1];
//					bot[j + 1] = temp;
//				}
//			}
//		}
//	}
//
//}