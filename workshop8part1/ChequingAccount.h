//*******************************************************************
//Reflection Workshop 8 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 20, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#ifndef SDDS_CHEQUINGACCOUNT_H_
#define SDDS_CHEQUINGACCOUNT_H_
#include <iostream>
#include "Account.h"
namespace sdds {
	class ChequingAccount :public Account {
		double m_transFee;
		double m_monthFee;
	public:
		ChequingAccount(double balance, double transFee, double monthFee);
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd();
		void display(std::ostream& os) const;

	};
}
#endif // !SDDS_SAVINGSACCOUNT_H_