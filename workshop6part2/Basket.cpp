//*******************************************************************
//Reflection Workshop 6 Part 2
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 5, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Basket.h"
using namespace std;
namespace sdds {
	void Basket::setEmpty()
	{
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0;
	}

	bool Basket::isEmpty() const
	{
		return m_fruits==nullptr;
	}

	Basket::Basket()
	{
		setEmpty();
	}

	Basket::Basket(const Fruit* f, int size, double price)
	{
		setEmpty();
		if (f != nullptr && size>0 && price>0 ) {
			this->m_fruits = new Fruit[size];
			for (int i = 0; i < size; i++) {
				this->m_fruits[i] = f[i];
			}
			this->m_cnt = size;
			this->m_price = price;
		}
		else {
			this->setEmpty();
		}
	}

	Basket::Basket(const Basket& toCopy)
	{
		setEmpty();
		*this = toCopy;
	}

	Basket& Basket::operator=(const Basket& toAssign)
	{
		if (this != &toAssign) {
			delete[] m_fruits;
			m_cnt = toAssign.m_cnt;
			m_price = toAssign.m_price;
			if (!toAssign.isEmpty()) {
				m_fruits = new Fruit[m_cnt];
				for (int i = 0; i < m_cnt; i++) {
					m_fruits[i] = toAssign.m_fruits[i];
				}
			}
			else
				m_fruits = nullptr;
		}
		return *this;
	}

	Basket::~Basket()
	{
		delete[] m_fruits;
		m_fruits = nullptr;
	}

	void Basket::setPrice(double price)
	{
		m_price = price;
	}

	Basket::operator bool() const
	{
		return !isEmpty();
	}

	Basket& Basket::operator+=(const Fruit f)
	{
		Fruit* temp{};
		temp = new Fruit[this->m_cnt + 1];
		for (int i = 0; i < m_cnt; i++) {
			temp[i] = m_fruits[i];
		}
		temp[m_cnt] = f;
		delete[] m_fruits;
		m_fruits = nullptr;
		m_fruits = temp;
		m_cnt += 1;
		return *this;
	}

	std::ostream& Basket::display(std::ostream& ostr) const
	{
		if (this->isEmpty()) {
			ostr << "The basket is empty!" << endl;
		}
		else {
			ostr << "Basket Content:" << endl;
			for (int i = 0; i < this->m_cnt; i++) {
				ostr.width(10);
				ostr << m_fruits[i].m_name<<": ";
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << m_fruits[i].m_qty << "kg" << endl;
				ostr.unsetf(ios::fixed);
			}
			ostr.setf(ios::fixed);
			ostr.precision(2);
			ostr << "Price: "<<m_price<< endl;
			ostr.unsetf(ios::fixed);
		}
		return ostr;
	}




	std::ostream& operator<<(std::ostream& os, const Basket& B)
	{
		return B.display(os);
	}

}