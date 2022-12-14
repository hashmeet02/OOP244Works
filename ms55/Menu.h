// Final Project Milestone 55
// Menu Module
// File  Menu.h
// Version 2.0
// Author   Hashmeet Singh Saini
// Revision History
// -----------------------------------------------------------
// Name                    Date              Reason
// Hashmeet Singh Saini    July 10th            Preliminary
// Hashmeet Singh Saini    July 14th            edited desplaymenu(); and addition of member function setTitle() in Menu class
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu;

	class MenuItem {
		char* m_content;
		friend class Menu;
		MenuItem();
		MenuItem(const char* content);
		MenuItem(const MenuItem& source) = delete;
		MenuItem& operator=(const MenuItem& source) = delete;
		~MenuItem();
		operator bool()const;
		operator const char*()const;
		std::ostream& write(std::ostream& os = std::cout)const;
	};

	class Menu {
		MenuItem m_title;
		MenuItem m_menuItems[MAX_MENU_ITEMS];
		int m_num_of_menu_items;
	public:
		Menu();
		Menu(const char* title);
		~Menu();
		void setTitle(const char* title);
		std::ostream& displayTitle(std::ostream& os = std::cout)const;
		std::ostream& displayMenu(std::ostream& os = std::cout)const;
		unsigned int run()const;
		unsigned int operator ~();
		Menu& operator<<(const char* menuitemConent);
		operator int()const;
		operator unsigned int()const;
		operator bool()const;
		const char* operator[](int index)const;
	};
	std::ostream& operator<<(std::ostream& leftOper, const Menu& righOper);

}
#endif