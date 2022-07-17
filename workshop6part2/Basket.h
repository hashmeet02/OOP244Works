//*******************************************************************
//Reflection Workshop 6 Part 2
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 5, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_
#include <iostream>
namespace sdds {
	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};
	struct Basket
	{
		Fruit* m_fruits{};
		int m_cnt{};
		double m_price{};
		void setEmpty();
		bool isEmpty()const;

	public:
		Basket();
		Basket(const Fruit* f, int size, double price);
		Basket(const Basket& toCopy);
		Basket& operator=(const Basket& toAssign);
		~Basket();
		void setPrice(double price);
		operator bool() const;
		Basket& operator+=(const Fruit f);
		std::ostream& display(std::ostream& ostr) const;
	};
	std::ostream& operator<<(std::ostream& os, const Basket& B);
}

#endif // !SDDS_BASKET_H_
