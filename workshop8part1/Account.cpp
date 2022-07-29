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
#include "Account.h"

using namespace std;
namespace sdds {
	Account::Account()
	{
		m_balance = 0;
	}
	Account::Account(double balance)
	{
		if (balance > 0) {
			m_balance = balance;
		}
		else {
			m_balance = 0;
		}
	}
	bool Account::credit(double amount)
	{
		bool success = false;
		if (amount > 0) {
			success = true;
			m_balance += amount;
		}
		else {
			success = false;
		}
		return success;
	}

	bool Account::debit(double amount)
	{
		bool success = false;
		if (amount > 0) {
			success = true;
			m_balance -= amount;
		}
		else {
			success = false;
		}
		return success;
	}

	double Account::balance() const
	{
		return m_balance;
	}

}