#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include "Power.h"

namespace sdds {
	/*const int MAX_NAME_LENGTH = 50;*/

	class Hero {
		char m_name[MAX_NAME_LENGTH + 1]{};
		Power* m_powers{};
		int m_num_of_powers{};
		int m_power_level{};
		int add_power(Power* p);
	public:
		void setEmpty();
		Hero();
		Hero(const char* name, const Power* p, int numPowers);
		~Hero();
		/*void createHero(const char* name, Power* p, int numPowers);*/
		
		int getPowerLevel()const;
		std::ostream& display(/*std::ostream& os*/)const;
		Hero& operator+=(Power& p);
		Hero& operator-=(int powerLevelReduc);
	};
	bool operator<(Hero& leftOpr, Hero& rightOpr);
	bool operator>(Hero& leftOpr, Hero& rightOpr);
	Hero& operator>>(Power& leftPower, Hero& rightHero);
	Hero& operator<<(Hero& leftHero, Power& rightPower);
	std::ostream& operator<<(std::ostream& leftOper, const Hero& righOper);

}

#endif // !SDDS_HERO_H
