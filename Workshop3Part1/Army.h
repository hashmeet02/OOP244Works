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

#ifndef SDDS_ARMY_H
#define SDDS_ARMY_H

#define MAX_NAME_LEN 50

namespace sdds {
	class Army {
		char m_nationality[MAX_NAME_LEN];
		int m_units;
		double m_power;
	public:
		void setEmpty();
		void createArmy(const char* country, double pow, int troops);
		void updateUnits(int troops);
		const char* checkNationality() const;
		int checkCapacity() const;
		double checkPower() const;
		bool isEmpty() const;
		bool isStrongerThan(const Army& army)const;
	};
	void battle(Army& arm1, Army& arm2);
	void displayDetails(const Army* armies, int size);
}

#endif // !SDDS_ARMMY_H

