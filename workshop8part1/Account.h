//*******************************************************************
//Reflection Workshop 8 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 20, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>
#include "iAccount.h"
namespace sdds {
	class Account:public iAccount {
		double m_balance;
	public:
		Account();
		Account(double balance);
		bool credit(double amount);
		bool debit(double amount);
	protected:
		double balance() const;
	};
}
#endif // !SDDS_ACCOUNT_H_