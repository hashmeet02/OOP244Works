// Final Project Milestone 2
// LibApp Module
// File  LibApp.h
// Version 1.0
// Author   Hashmeet Singh Saini
// Revision History
// -----------------------------------------------------------
// Name                    Date              Reason
// Hashmeet Singh Saini    July 14th            Preliminary
// -----------------------------------------------------------
// Name:			Hashmeet Singh Saini
// Seneca ID : hsaini28
// Student No. : 153070214
// Date : July 14, 2022
// 
// I have done all the coding by myselfand only copied the code
// that my professor provided to complete my project milestones.
// ------------------------------------------------------------
/////////////////////////////////////////////////////////////////

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <iostream>
#include "Menu.h"
namespace sdds {
	class LibApp {
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		bool confirm(const char* message);
		void load();  
		void save();  
		void search();  
		void returnPub();
	public:
		LibApp();
		void newPublication();
		void removePublication();
		void checkOutPub();
		void run();

	};
}
#endif