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
#include <fstream>
#include "Utils.h"
#include "LibApp.h"
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"

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
		ifstream filein(m_fileName);
		char pType{};
		for (int row = 1; filein; row++) {
			filein >> pType;
			filein.ignore();
			if (filein) {
				if (pType == 'P') {
					m_publication[row - 1] = new Publication;
				}
				else if (pType=='B') {
					m_publication[row - 1] = new Book;
				}
				if (m_publication[row - 1]) {
					filein >> *m_publication[row - 1];
					m_numLoadedPubs += 1;
				}
			}
			m_lastRefNum = m_publication[m_numLoadedPubs - 1]->getRef();
		}
		/*m_lastRefNum = m_publication[m_numLoadedPubs - 1]->getRef();*/

	}
	void LibApp::save()
	{
		cout << "Saving Data" << endl;
		ofstream fileout(m_fileName);
		for (int i = 0; i < m_numLoadedPubs; i++) {
			if (m_publication[i]->getRef() != 0) {
				fileout << *m_publication[i]<<endl;
			}
		}

	}
	int LibApp::search(int searchType)
	{
		int selectedTitle = 0;
		int selection = 0;
		char selectedType=0;
		char searchTitle[256];
		/*cout << "Searching for publication" << endl;*/
		PublicationSelector results("Select one of the following found matches:");
		selection=m_pubTypeMenu.run();
		if (selection == 1) {
			selectedType = 'B';
		}
		else if (selection == 2) {
			selectedType = 'P';
		}
		if (selection == 0) {
			cout << "Aborted!" << endl;
		}
		else {
			
			cout << "Publication Title: ";
			/*cin.ignore(1000, '\n');*/
			cin.getline(searchTitle, 256, '\n');
			for (int i = 0; i < m_numLoadedPubs; i++) {
				if (m_publication[i]->getRef() != 0 && m_publication[i]->type() == selectedType && m_publication[i]->operator==(searchTitle)) {
					switch (searchType)
					{
					case 1:
						results << m_publication[i];
						break;
					case 2:
						if (m_publication[i]->onLoan()) {
							results << m_publication[i];
						}
						break;
					case 3:
						if (!(m_publication[i]->onLoan())) {
							results << m_publication[i];
						}
						break;
					default:
						break;
					}
				}
			}
			if (results) {
				results.sort();
				selectedTitle = results.run();
				if (selectedTitle == 0) {
					cout << "Aborted!" << endl;
				}
			}
			else {
				cout << "No matches found!" <<endl;
			}
		}
		return selectedTitle;
		
	}
	void LibApp::returnPub()
	{
		int selection = 0;
		bool flag = 0, flag2=1;
		double penalty;
		Date today;
		int days = 0;
		cout << "Return publication to the library" << endl;
		selection=search(2);
		flag = confirm("Return Publication?");
		if (flag) {
			for (int i = 0; i < m_numLoadedPubs && flag2; i++) {
				if (m_publication[i]->getRef() == selection) {
					flag2 = 0;
					days = today - m_publication[i]->checkoutDate();
					if (days > 15) {
						penalty = 50 * (days - 15);
						cout << "Please pay $" << penalty << " penalty for being " << days - 15 << " days late!" << endl;
						m_publication[i]->set(0);
						cout << "Publication returned" << endl << endl;
						m_changed = true;
					}

				}
			}
		}
	}
	LibApp::LibApp(const char* filename)
	{
		m_changed = false;
		m_mainMenu.setTitle("Seneca Library Application");
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		m_pubTypeMenu.setTitle("Choose the type of publication:");
		m_pubTypeMenu << "Book" << "Publication";
		U.strcpy(m_fileName, filename);
		load();
	}
	LibApp::~LibApp()
	{
		for (int i = 0; m_publication[i]; i++) {
			delete m_publication[i];
			m_publication[i] = nullptr;
		}
	}
	Publication* LibApp::getPub(int libRef)
	{
		Publication *tempPub{};
		for (int i = 0; i < m_numLoadedPubs; i++) {
			if (m_publication[i]->getRef() == libRef) {
				tempPub = m_publication[i];
			}
		}
		return tempPub;		
	}

	void LibApp::newPublication()
	{
		bool flag = 0;
		int selection = 0;
		Publication* tempPub{};
		cout << "Adding new publication to the library" << endl;
		selection=m_pubTypeMenu.run();
		if (selection == 1) {
			tempPub = new Book;
		}
		else if (selection == 2) {
			tempPub = new Publication;
		}
		tempPub->read(cin);
		if (cin.fail()) {
			cin.ignore(1000, '\n');
			cout << "Aborted!" << endl;
			
		}
		else {
			flag = confirm("Add this publication to the library?");
			if (!flag) {
				cout << "Aborted!" << endl;
			}
			else {
				m_lastRefNum += 1;
				/*if (selection == 1) {
					m_publication[m_numLoadedPubs] = new Book;
				}
				else if (selection == 2) {
					m_publication[m_numLoadedPubs] = new Publication;
				}*/
				m_publication[m_numLoadedPubs] = tempPub;
				m_publication[m_numLoadedPubs]->setRef(m_lastRefNum);
				m_numLoadedPubs += 1;
				m_changed = true;
				cout << "Publication added" << endl;
			}
		}
		if (!m_publication[m_numLoadedPubs - 1]) {
			cout << "Failed to add publication!" << endl;
		}
		
		cout << endl;
	}
	void LibApp::removePublication()
	{
		bool flag = 0;
		int selection1 = 0;
		int location = 0;
		//int selection2 = 0;
		cout << "Removing publication from the library" << endl;
		//selection1 = m_pubTypeMenu.run();
		selection1 = search(1);
		for (int i = 0; i < m_numLoadedPubs; i++) {
			if (m_publication[i]->getRef() == selection1) {
				cout << *m_publication[i] << endl;
				location = i;
			}
		}
		flag = confirm("Remove this publication from the library?");
		if (flag) {
			m_publication[location]->setRef(0);
			m_changed = true;
			cout << "Publication removed" << endl;
		}
		cout << endl;

	}
	void LibApp::checkOutPub()
	{
		int selection = 0, memberId=0, location=0;
		bool flag = 0, flag2 = 1; /*flag3=0*/
		cout << "Checkout publication from the library" << endl;
		selection = search(3);
		if (selection) {
			for (int i = 0; i < m_numLoadedPubs; i++) {
				if (m_publication[i]->getRef() == selection) {
					cout << *m_publication[i] << endl;
					location = i;
				}
			}
			flag = confirm("Check out publication?");
			if (flag) {
				while (flag2) {
					cout << "Enter Membership number: ";
					cin >> memberId;
					if (memberId > 9999 && memberId < 100000) {
						flag2 = 0;
						m_publication[location]->set(memberId);
						m_changed = true;
						cout << "Publication checked out" << endl;
						/*for (int i = 0; i < m_numLoadedPubs; i++) {
							if (m_publication[i]->getRef() == selection) {
								flag3 = 1;
								m_publication[i]->set(memberId);
								m_changed = true;
								cout << "Publication checked out" << endl;
							}
						}*/
						//if (!flag3) {
						//	cout << "Invalid membership number, try again: ";
						//}

					}
					else {
						cout << "Invalid membership number, try again: ";
					}
				}
			}
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