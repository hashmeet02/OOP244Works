//***********************************************************
//Reflection Workshop 2 Part 2
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : May 30, 2022
//I have done all the coding by myselfand only copied the code
//that my professor provided to complete my workshopsand 
// assignments.
//* **********************************************************

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Army.h"
#include<string.h>
#include<iomanip>

using namespace std;
namespace sdds {
	
	void Army::setEmpty() {
		strcpy(m_nationality,"");
		m_units = 0;
	}

	void Army::createArmy(const char* country, double pow, int troops) {

		bool countryFlag = false, powerFlag=false, troopsFlag=false;
		
		if (country != nullptr && strlen(country) > 0) countryFlag = true;
		if (pow > 0) powerFlag = true;
		if (troops > 0) troopsFlag = true;
		if (countryFlag && troopsFlag && powerFlag) {
			strcpy(m_nationality, country);
			m_power = pow;
			m_units = troops;
		}
	}

	void Army::updateUnits(int troops) {
		m_units += troops;
		m_power += (0.25 * troops);
	}

	const char* Army::checkNationality() const{
		return m_nationality;
	}

	int Army::checkCapacity() const {
		return m_units;
	}

	double Army::checkPower() const {
		return m_power;
	}

	bool Army::isEmpty() const {
		bool nationalityFlag = false, unitsFlag = false;
		if (!strcmp(m_nationality, "")) nationalityFlag= true;
		if (m_units == 0) unitsFlag = true;
		if (nationalityFlag && unitsFlag) return true;
		else return false;
	}

	bool Army::isStrongerThan(const Army& army)const {
		if (m_power > army.m_power) return true;
		else return false;
	}

	void battle(Army& arm1, Army& arm2) {
		if (!arm1.isEmpty() && !arm2.isEmpty()) {
			if (arm1.isStrongerThan(arm2)) {
				arm2.updateUnits(int(-(0.5 * arm2.checkCapacity())));
				cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", " << arm1.checkNationality() << " is victorious!" << endl;
			}
			else {
				arm1.updateUnits(int(-(0.5 * arm1.checkCapacity())));
				cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", " << arm2.checkNationality() << " is victorious!" << endl;
			}
		}
	}

	void displayDetails(const Army* armies, int size) {

		cout << "Armies reporting to battle: " << endl;
		for (int i = 0; i < size; i++) {
			if (!armies[i].isEmpty())
			cout << "Nationality: " << armies[i].checkNationality() << ", Units Count: " << armies[i].checkCapacity() << ", Power left: " << fixed<< setprecision(1)<<armies[i].checkPower()<<endl;
		}
	}

}