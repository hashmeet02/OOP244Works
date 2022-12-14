// Final Project Milestone 55
// LibApp Module
// File  LibApp.h
// Version 2.0
// Author   Hashmeet Singh Saini
// Revision History
// -----------------------------------------------------------
// Name                    Date              Reason
// Hashmeet Singh Saini    July 14th            Preliminary
// Hashmeet Singh Saini    July 30th            Addition of new attributes
// 
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

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <iostream>
#include "Menu.h"
#include "Lib.h"
#include "Publication.h"

namespace sdds {
	class LibApp {
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		char m_fileName[256]{};
		Publication* m_publication[SDDS_LIBRARY_CAPACITY]{}; //check
		int m_numLoadedPubs=0;
		int m_lastRefNum=0;
		Menu m_pubTypeMenu;

		bool confirm(const char* message);
		void load();  
		void save();  
		int search(int searchType=1);
		void returnPub();
	public:
		LibApp(const char* filename);
		~LibApp();
		Publication* getPub(int libRef);
		void newPublication();
		void removePublication();
		void checkOutPub();
		void run();

	};
}
#endif