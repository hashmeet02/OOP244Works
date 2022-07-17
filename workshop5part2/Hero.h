//*******************************************************************
//Reflection Workshop 5 Part 2
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : June 15, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include "Power.h"

namespace sdds {

	class Hero {
		//Class members
		char m_name[MAX_NAME_LENGTH + 1]{};
		Power* m_powers{};
		int m_num_of_powers{};
		int m_power_level{};
		int add_power(Power* p);

	public:
		
		//constructors and destructors
		Hero();
		Hero(const char* name, const Power* p, int numPowers);
		~Hero();

		//public class member functions
		void setEmpty();
		int getPowerLevel()const;
		std::ostream& display()const;

		//member operators
		Hero& operator+=(Power& p);
		Hero& operator-=(int powerLevelReduc);
	};
	//helper operator functions
	bool operator<(Hero& leftOpr, Hero& rightOpr);
	bool operator>(Hero& leftOpr, Hero& rightOpr);
	Hero& operator>>(Power& leftPower, Hero& rightHero);
	Hero& operator<<(Hero& leftHero, Power& rightPower);
	std::ostream& operator<<(std::ostream& leftOper, const Hero& righOper);

}

#endif // !SDDS_HERO_H
