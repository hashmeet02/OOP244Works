#include <iostream>
#include <cstring>
#include "CleanerBot.h"
#include "Utils.h"


using namespace std;
namespace sdds {

	//default constructor
	CleanerBot::CleanerBot() {
		resetInfo();
	}

	//constructor with arguments
	CleanerBot::CleanerBot(const char* location,
		double battery,
		int brush,
		bool active) {
		resetInfo();
		set(location, battery, brush, active);
	}

	//deconstructor
	CleanerBot::~CleanerBot() {
		deallocate();
	}

	//resets the object
	CleanerBot& CleanerBot::resetInfo() {
		m_location = nullptr;
		m_battery = 0;
		m_brush = 0;
		m_active = 0;
		return *this;
	}

	//deallocates all the dynamically allocated memory
	CleanerBot& CleanerBot::deallocate()
	{
		delete[] m_location;
		m_location = nullptr;
		return *this;
	}

	//sets the object to given values
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

	//sets the location of bot
	CleanerBot& CleanerBot::setLocation(const char* location) {
		deallocate();
		m_location = U.aloCpy(location);
		return *this;
	};

	//sets the activity of bot
	CleanerBot& CleanerBot::setActive(bool active) {

		m_active = active;
		return *this;
	}

	//gets the location of bot
	const char* CleanerBot::getLocation() const
	{
		return m_location;
	}

	//gets the battery of bot
	const double CleanerBot::getBattery() const
	{
		return m_battery;
	}

	//gets the number of brushes of bot
	const int CleanerBot::getBrush() const
	{
		return m_brush;
	}

	//gets the activity of bot
	const bool CleanerBot::isActive() const
	{
		return m_active;
	}

	//checks if a class object is valifd or not
	const bool CleanerBot::isValid() const
	{
		return m_location && m_location[0] && m_battery>0;
	}

	//displays the content of class object
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

	void displayHeader()
	{
		cout << "         ------ Cleaner Bots Report -----" << endl;
		cout << "     ---------------------------------------" << endl;
		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
		cout << "|------------+---------+--------------------+--------|" << endl;
	}

	void lowBatteryHeader(int lowDevices)
	{
		cout << endl;
		cout << "|====================================================|" << endl;
		cout << "| LOW BATTERY WARNING:                               |" << endl;
		cout << "|====================================================|" << endl;
		cout << "| Number of robots to be charged: ";
		cout.width(19);
		cout.setf(ios::left);
		cout << lowDevices << "|" << endl;
		cout << "| Sorting robots based on their available power:     |" << endl;
		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
		cout << "|------------+---------+--------------------+--------|" << endl;
	}

	int report(CleanerBot* bot, const short num_bots) {

		displayHeader();
		int lowBatCounter = 0;
		int largestBattery = 0;
		double bat[8];
		for (int i = 0; i < num_bots; i++) {
			if (bot[i].isValid()) {
				bot[i].display();
				if (bot[i].getBattery() < 30) {
					lowBatCounter++;
				}
			}

		}
		lowBatteryHeader(lowBatCounter);
		
		
		for (int i = 0; i < 8; i++) {
			if (bot[i].isValid()) {
				bat[i] = bot[i].getBattery();
			}
			else {
				bat[i] = -1;
			}
		}
		for (int i = 0; i < num_bots; i++) {
			if (bat[i]!=-1.0) {
				double x = bat[i];
				for (int j = 0; j < num_bots; j++) {
					if (x <= bat[j]) {
						x = bat[j];
						largestBattery = j;
					}
				}
				bat[largestBattery] = 0.0;
				bot[largestBattery].display();
			}
		}
		cout << "|====================================================|" << endl;
		return 1;
	}
}

