// Final Project Milestone 54
// Book Module
// File  Book.h
// Version 1.0
// Author  Hashmeet Singh Saini
// Revision History
// -----------------------------------------------------------
// Name                    Date                 Reason
// Hashmeet Singh Saini    July 25th            Preliminary
// -----------------------------------------------------------
// Name:			Hashmeet Singh Saini
// Seneca ID : hsaini28
// Student No. : 153070214
// Date : July 30th, 2022
// 
// I have done all the coding by myselfand only copied the code
// that my professor provided to complete my project milestones.
// ------------------------------------------------------------
/////////////////////////////////////////////////////////////////

#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include "Publication.h"

namespace sdds {
	class Book : public Publication {
		char* m_author;
	public:
		Book();
		Book(const Book& toCopy);
		~Book();
		virtual char type()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		void set(int member_id);
		operator bool() const;
		Book& operator=(const Book& toAssing);
	};
}
#endif // !SDDS_BOOK_H_

