// Final Project Milestone 54
// Publication Module
// File  Publication.h
// Version 2.0
// Author  Hashmeet Singh Saini
// Revision History
// -----------------------------------------------------------
// Name                    Date                 Reason
// Hashmeet Singh Saini    July 23rd            Preliminary
// Hashmeet Singh Saini	   July 25th			legth modifications to the read function
// -----------------------------------------------------------
// Name:			Hashmeet Singh Saini
// Seneca ID : hsaini28
// Student No. : 153070214
// Date : July 25th, 2022
// 
// I have done all the coding by myselfand only copied the code
// that my professor provided to complete my project milestones.
// ------------------------------------------------------------
/////////////////////////////////////////////////////////////////
#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_
#include <iostream>
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"
namespace sdds {
	const int MAX_LOC_LENGTH = 4;
	const int MAX_TITLE_LEN = 225;

	class Publication : public Streamable {
		char* m_title{};
		char m_shelfld[MAX_LOC_LENGTH+1]{};
		int m_membership;
		int m_libRef;
		Date m_date;
	public:
		Publication();
		void setDefault();
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute. 
		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		operator bool() const;
		~Publication();
		Publication(const Publication& toCopy);
		Publication& operator=(const Publication& toAssing);
	};
}
#endif