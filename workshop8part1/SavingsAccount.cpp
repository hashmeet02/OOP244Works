//*******************************************************************
//Reflection Workshop 8 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 20, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SavingsAccount.h"

using namespace std;
namespace sdds {
	SavingsAccount::SavingsAccount(double balance, double interest):Account{balance}
	{
		if (interest > 0) {
			m_interest = interest;
		}
		else {
			m_interest = 0;
		}
	}
	void SavingsAccount::monthEnd()
	{
		double amount = 0;
		amount = m_interest * (Account::balance());
		Account::credit(amount);
	}
	void SavingsAccount::display(std::ostream& os) const
	{
		os << "Account type: Savings"<<endl;
		os.setf(ios::fixed);
		cout.precision(2);
		os << "Balance: $"<<Account::balance() << endl;
		os << "Interest Rate (%): "<<m_interest*100 << endl;		
	}
}