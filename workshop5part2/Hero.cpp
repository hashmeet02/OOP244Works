#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include "Hero.h"
#include "Power.h"

using namespace std;
namespace sdds {
	void Hero::setEmpty()
	{
		m_name[0] = '\0';
		m_powers = nullptr;
		m_num_of_powers = 0;
		m_power_level = 0;
	}

	Hero::Hero()
	{
		this->setEmpty();
	}

	Hero::Hero(const char* name, const Power* p, int numPowers)
	{
		int raritySum = 0;
		if ((name && name[0] != '\0') && numPowers > 0) {
			strcpy(this->m_name, name);
			this->m_powers = new Power[numPowers];
			for (int i = 0; i < numPowers; i++) {
				if (p[i].checkName()) {
					this->m_powers[i] = p[i];
					raritySum += m_powers[i].checkRarity();
				}
			}
			this->m_num_of_powers = numPowers;
			this->m_power_level = raritySum * numPowers;
		}
	}

	Hero::~Hero()
	{
		delete[] m_powers;
		m_powers = nullptr;
	}

	int Hero::add_power(Power* p)
	{
		int raritySum = 0;
		Power* temp{};
		temp = new Power[this->m_num_of_powers + 1];
		for (int i = 0; i < m_num_of_powers; i++) {
			temp[i] = m_powers[i];
			raritySum += temp[i].checkRarity();
		}
		temp[m_num_of_powers] = *p;
		raritySum += temp[m_num_of_powers].checkRarity();
		delete[] m_powers;
		m_powers = nullptr;
		m_powers = temp;
		m_num_of_powers += 1;
		this->m_power_level = raritySum * m_num_of_powers;
		return m_num_of_powers;

		//m_powers[m_num_of_powers + 1] = *p;
		//m_num_of_powers += 1;
		//for (int i = 0; i < m_num_of_powers; i++) {
		//	if (p[i].checkName()) {
		//		m_powers[i] = p[i];
		//		raritySum += m_powers[i].checkRarity();
		//	}
		//}
		//this->m_power_level = raritySum * m_num_of_powers;
		//return m_num_of_powers;
	}

	int Hero::getPowerLevel() const
	{
		return this->m_power_level;
	}

	std::ostream& Hero::display(/*std::ostream& os*/) const
	{
		/*cout.setf(std::ios::left);*/
		cout << "Name: " << this->m_name << endl;
		displayDetails(this->m_powers, this->m_num_of_powers);
		cout << "Power Level: " << this->m_power_level;
		return cout;
	}

	Hero& Hero::operator+=(Power& p)
	{
		m_num_of_powers = add_power(&p);
		return *this;
	}

	Hero& Hero::operator-=(int powerLevelReduc)
	{
		m_power_level -= powerLevelReduc;
		return *this;
	}


	//std::ostream& Book::display(std::ostream& os) const
	//{
	//	os << "Title:\'" << m_title << "\'" << endl;
	//	os << "Author: \'" << m_author << "\'" << endl;
	//	for (int i = 0; i < m_num_chapters; i++) {
	//		m_chapters[i].display(os);
	//	}
	//	return os;
	//}

	bool operator<(Hero& leftOpr, Hero& rightOpr)
	{
		return leftOpr.getPowerLevel() < rightOpr.getPowerLevel();
	}

	bool operator>(Hero& leftOpr, Hero& rightOpr)
	{
		return leftOpr.getPowerLevel() > rightOpr.getPowerLevel();
	}

	Hero& operator>>(Power& leftPower, Hero& rightHero)
	{
		return rightHero += leftPower;
	}

	Hero& operator<<(Hero& leftHero, Power& rightPower)
	{
		return leftHero += rightPower;
	}

	std::ostream& operator<<(std::ostream& leftOper, const Hero& righOper) {
		return righOper.display(/*leftOper*/);
	}

}