// Final Project Milestone 2
// LibApp Module
// File  LibApp.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
#include "LibApp.h"
using namespace std;
namespace sdds {
	bool LibApp::confirm(const char* message)
	{
		int s;
		Menu m1(message);
		m1 << "Yes";
		s = m1.run();
		return s == 1;
	}

	void LibApp::load()
	{
		cout << "Loading Data" << endl;
	}
	void LibApp::save()
	{
		cout << "Saving Data" << endl;

	}
	void LibApp::search()
	{
		cout << "Searching for publication" << endl;
	}
	void LibApp::returnPub()
	{
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl<<endl;
		m_changed = true;
	}
	LibApp::LibApp()
	{
		m_changed = false;
		m_mainMenu.setTitle("Seneca Library Application");
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		load();
	}
	void LibApp::newPublication()
	{
		bool flag = 0;
		cout << "Adding new publication to library" << endl;
		flag = confirm("Add this publication to library?");
		if (flag) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
		cout << endl;
	}
	void LibApp::removePublication()
	{
		bool flag = 0;
		cout << "Removing publication from library" << endl;
		search();
		flag = confirm("Remove this publication from the library?");
		if (flag) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}
		cout << endl;

	}
	void LibApp::checkOutPub()
	{
		bool flag = 0;
		search();
		flag = confirm("Check out publication?");
		if (flag) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
		cout << endl;

	}
	void LibApp::run()
	{
		int selection1;
		int selection2;
		bool selection3=0;
		bool flag = true;
		while (flag) {
			selection1 = m_mainMenu.run();
			if (selection1 == 1) {
				newPublication();
			}
			else if (selection1 == 2) {
				removePublication();
			}
			else if (selection1 == 3) {
				checkOutPub();
			}
			else if (selection1 == 4) {
				returnPub();
			}
			else if (selection1 == 0) {
				if (m_changed) {
					selection2=m_exitMenu.run();
					if (selection2 == 1) {
						save();
						flag = false;
					}
					else if (selection2 == 2) {
						flag = true;
						cout << endl;
					}
					else if (selection2 == 0) {
						selection3 = confirm("This will discard all the changes are you sure?");
						if (selection3) {
							flag = false;
						}
						else flag = true;
					}
				}
				else flag = false;
			}
		}
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
		//do {
		//    selection1 = m_mainMenu.run();
		//    if (selection1) {
		//        if (selection1 == 1) {
		//            newPublication();
		//        }
		//        else if (selection1 == 2) {
		//            removePublication();
		//        }
		//        else if (selection1 == 3) {
		//            checkOutPub();
		//        }
		//        else if (selection1 == 4) {
		//            returnPub();
		//        }

		//    }
		//} while (selection1 != 0 || (selection2=(m_exitMenu.run()))!=2);
		//if (selection2 == 1) {
		//    save();
		//}
		//else if (selection2 == 0) {
		//    confirm("This will discard all the changes are you sure?")
		//}

	}
}