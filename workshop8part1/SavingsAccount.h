//*******************************************************************
//Reflection Workshop 8 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 20, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#ifndef SDDS_SAVINGSACCOUNT_H_
#define SDDS_SAVINGSACCOUNT_H_
#include <iostream>
#include "Account.h"
namespace sdds {
	class SavingsAccount :public Account {
		double m_interest;
	public:
		SavingsAccount(double balance, double interest);
		void monthEnd();
		void display(std::ostream& os) const;
	
	};
}
#endif // !SDDS_SAVINGSACCOUNT_H_