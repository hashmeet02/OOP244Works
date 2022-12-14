// Final Project Milestone 53
// Streamable Module
// File  Streamable.h
// Version 1.0
// Author  Hashmeet Singh Saini
// Revision History
// -----------------------------------------------------------
// Name                    Date                 Reason
// Hashmeet Singh Saini    July 23rd            Preliminary
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
#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_
#include <iostream>

namespace sdds {

	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& os = std::cout)const = 0;
		virtual std::istream& read(std::istream& is = std::cin) = 0;
		virtual bool conIO(std::ios& io)const = 0;
		virtual operator bool()const=0;
		virtual ~Streamable(){ };
	};
	std::ostream& operator<<(std::ostream& os, const Streamable& RO);
	std::istream& operator>>(std::istream& is, Streamable& RO);

}
#endif