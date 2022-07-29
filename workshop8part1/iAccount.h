//*******************************************************************
//Reflection Workshop 8 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 20, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#ifndef SDDS_IACCOUNT_H_
#define SDDS_IACCOUNT_H_
namespace sdds {
	class iAccount {
	public:
		virtual bool credit(double)=0;
		virtual bool debit(double)=0;
		virtual void monthEnd()=0;
		virtual void display(std::ostream&) const=0;
		virtual ~iAccount(){ };
	};
	iAccount* CreateAccount(const char* type, double balance);
}
#endif // !SDDS_IACCOUNT_H_
