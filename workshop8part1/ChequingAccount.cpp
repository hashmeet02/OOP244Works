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
#include "ChequingAccount.h"


using namespace std;
namespace sdds {
	ChequingAccount::ChequingAccount(double balance, double transFee, double monthFee) :Account{ balance }
	{
		if (transFee > 0) {
			m_transFee = transFee;
		}
		else {
			m_transFee = 0;
		}
		if (monthFee > 0) {
			m_monthFee = monthFee;
		}
		else {
			m_monthFee = 0;
		}
	}
	bool ChequingAccount::credit(double amount)
	{
		bool success = false;
		if (Account::credit(amount)) {
			if (Account::debit(m_transFee)) {
				success = true;
			}
		}

		return success;
	}

	bool ChequingAccount::debit(double amount)
	{
		bool success = false;
		if (Account::debit(amount)) {
			if (Account::debit(m_transFee)) {
				success = true;
			}
		}

		return success;
	}

	void ChequingAccount::monthEnd()
	{
		Account::debit(m_monthFee);
	}

	void ChequingAccount::display(std::ostream& os) const
	{
		os << "Account type: Chequing" << endl;
		os.setf(ios::fixed);
		cout.precision(2);
		os << "Balance: $" << Account::balance() << endl;
		os << "Per Transaction Fee: " << m_transFee << endl;
		os << "Monthly Fee: " << m_monthFee << endl;
	}
}