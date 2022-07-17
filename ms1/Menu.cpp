// Final Project Milestone 1
// Menu Module
// File  Menu.cpp
// Version 1.0
// Author   Hashmeet Singh Saini
// Revision History
// -----------------------------------------------------------
// Name                    Date              Reason
// Hashmeet Singh Saini    July 10th            Preliminary
// -----------------------------------------------------------
// Name:			Hashmeet Singh Saini
// Seneca ID : hsaini28
// Student No. : 153070214
// Date : July 10, 2022
// 
// I have done all the coding by myselfand only copied the code
// that my professor provided to complete my project milestones.
// ------------------------------------------------------------
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
#include "Menu.h"
using namespace std;
namespace sdds {
	MenuItem::MenuItem() {
		m_content = nullptr;
	}
	MenuItem::MenuItem(const char* content) {
		m_content = nullptr;
		m_content = U.aloCpy(content);
	}
	MenuItem::~MenuItem()
	{
		delete[] m_content;
		m_content = nullptr;
	}
	MenuItem::operator bool() const
	{
		return m_content == nullptr;
	}
	MenuItem::operator const char* () const
	{
		return m_content;
	}

	std::ostream& MenuItem::write(std::ostream& os) const
	{
		os << m_content;
		return os;
	}

	Menu::Menu()
	{
		m_num_of_menu_items = 0;
	}

	Menu::Menu(const char* title)
	{
		m_title.m_content=U.aloCpy(title);
		m_num_of_menu_items = 0;
	}

	Menu::~Menu()
	{
		m_title.~MenuItem();
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
			m_menuItems[i].~MenuItem();
		}
	}

	std::ostream& Menu::displayTitle(std::ostream& os) const
	{
		if (m_title !=nullptr) {
			m_title.write();
		}
		return os;
	}

	std::ostream& Menu::displayMenu(std::ostream& os) const
	{
		displayTitle();
		if (m_title.m_content && m_title.m_content[0] != '\0') {
			os << ":" << endl;
		}
		for (int i = 0; i < m_num_of_menu_items; i++) {
			os.width(2);
			os << i + 1 << "- ";
			m_menuItems[i].write();
			os<< endl;
		}
		os << " 0- Exit" << endl << "> ";
		return os;
	}

	unsigned int Menu::run() const
	{
		int selection;
		bool flag = true;
		displayMenu();
		while (flag) {
			cin>> selection;
			if (cin.fail()) {
				cin.clear();
				cout << "Invalid Selection, try again: ";
			}
			else
			{
				if (selection < 0 || selection > m_num_of_menu_items) {
					cout << "Invalid Selection, try again: ";
				}
				else {
					flag = false;
				}

			}
			cin.ignore(1000, '\n');
		}
		return selection;
	}

	unsigned int Menu::operator~()
	{
		int selection = run();
		return selection;
	}

	Menu& Menu::operator<<(const char* menuitemConent) {
		if (m_num_of_menu_items < (int)MAX_MENU_ITEMS) {
			m_menuItems[m_num_of_menu_items].m_content = U.aloCpy(menuitemConent);
			m_num_of_menu_items += 1;
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& leftOper, const Menu& righOper) {
		return righOper.displayTitle();
	}
	Menu::operator int() const
	{
		return m_num_of_menu_items;
	}
	Menu::operator unsigned int() const
	{
		return m_num_of_menu_items;
	}
	Menu::operator bool()const {
		return m_num_of_menu_items > 0;
	}
	const char * Menu::operator[](int index)const {
		return (const char*)m_menuItems[index % m_num_of_menu_items];
	}
}