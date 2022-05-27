#define _CRT_SECURE_NO_WARNINGS
#include "BirthDate.h"
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
namespace sdds {
	FILE* fp=nullptr;
	Employee* employees = nullptr;
	Employee* eligibleEmp = nullptr;
	int noOfEmployees = 0;
	int empCounter = 0;

	bool flag = false;
	bool testLoad = false;
	bool totalTest = false;

	bool openFile(const char* filename) {
		fp = fopen(filename, "r");
		return fp != NULL;
	}

	bool beginSearch(const char* filename) {
		int i = 0;
		
		if (openFile(filename)){			
			noOfEmployees = noOfRecords();
			cout << "Birthdate search program" << endl;
			flag = true;
			employees = new Employee[noOfEmployees];
			for (i = 0; i < noOfEmployees; i++) {
				testLoad = loadData(employees[i]);
				if (!testLoad) {
					cout << "error: incorrect number of records read; the data is possibly corrupted." << endl;
					totalTest = false;
				}
				else {
					totalTest = true;
				}
			}
			if (fp) fclose(fp);
			return totalTest;
		}
		else {
			cout << "Data file " << "\"" << filename << "\"" << " not found!" << endl;
			flag = false;
		}
		return flag;
	}

	bool readBirthDate(int month) {
		int i = 0, j=0;
		bool flag = false;

		for (i = 0; i < noOfEmployees; i++) {
			if (employees[i].m_date.m_month == month) {
				empCounter++;
				flag = true;
			}
			eligibleEmp = new Employee[empCounter];
		}
		for (i = 0; i < noOfEmployees; i++) {
			if (employees[i].m_date.m_month == month) {
				eligibleEmp[j] = employees[i];
				j++;
			}
		}
		return flag;
	}

	void sort() {
		int i, j;
		Employee temp;
		for (i = empCounter - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (eligibleEmp[j].m_date.m_year > eligibleEmp[j + 1].m_date.m_year) {
					temp = eligibleEmp[j];
					eligibleEmp[j] = eligibleEmp[j + 1];
					eligibleEmp[j + 1] = temp;
				}
				else if (eligibleEmp[j].m_date.m_year == eligibleEmp[j + 1].m_date.m_year) {
					if (eligibleEmp[j].m_date.m_day > eligibleEmp[j + 1].m_date.m_day) {
						temp = eligibleEmp[j];
						eligibleEmp[j] = eligibleEmp[j + 1];
						eligibleEmp[j + 1] = temp;
					}
				}
			}
		}
	}

	void displayBirthdays() {
		int i = 0;
		cout << empCounter << " birthm_date found:" << endl;
		for (i = 0; i < empCounter; i++) {
			cout << i + 1 << ") " << eligibleEmp[i].m_Name << ":" << endl;
			cout << eligibleEmp[i].m_date.m_year << "-" << eligibleEmp[i].m_date.m_month << "-" << eligibleEmp[i].m_date.m_day << endl;
			cout << "===================================" << endl;
		}
	}
	void deallocate() {
		for (int i = 0; i < noOfEmployees; i++) {
			delete[] employees[i].m_Name;
			employees[i].m_Name = nullptr;
		}
		delete[] employees;
		employees = nullptr;
		delete[] eligibleEmp;
		eligibleEmp = nullptr;

	}

	void endSearch() {
		cout << "Birthdate Search Program Closed." << endl;
	}

	// Find the number of Records in The file
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fp, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fp);
		return noOfRecs+1;

	}

	bool loadData(Employee& emp) {
		int test = 0;
		int flag = false;
		char tempName[256];
		int length;

		test = fscanf(fp, "%[^,],%d/%d/%d", tempName, &emp.m_date.m_month,&emp.m_date.m_day,&emp.m_date.m_year);
		if (test == 4) {
			length = strlen(tempName) + 1;
			emp.m_Name = new char[length];
			strcpy(emp.m_Name, tempName);

			flag = true;
		}
		return flag;
	}
}


