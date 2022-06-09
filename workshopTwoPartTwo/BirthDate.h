//***********************************************************
//Reflection Workshop 2 Part 2
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : May 28, 2022
//I have done all the coding but received help from professor
//Fardad Soleimanloo in struct definition by myself and only
//copied the code that my professor provided to complete my
//workshops and assignments.
//* **********************************************************
#ifndef SDDS_BIRTHDATE_H
#define SDDS_BIRTHDATE_H

namespace sdds {
	struct Date {
		int m_month;
		int m_day;
		int m_year;
	};
	struct Employee {
		char* m_Name;
		Date m_date;
	};

	//Accepts filename and importing data from the file to a struct
	bool beginSearch(const char* filename);
	
	//Opens the file and returns true if successfull
	bool openFile(const char* filename);

	//Counts the number of records in the file
	int noOfRecords();

	//loads the data from the file into the struct
	bool loadData(Employee& emp);

	//Matches what records in the structure match with the user
	bool readBirthDate(int month);

	//sorts the data according to the age
	void sort();

	//displays the selected sorted content
	void displayBirthdays();

	//deallocate all the dynamic memory allocated
	void deallocate();

	//displays the end message
	void endSearch();
	
	//Global Variables
	extern Employee* employees;
	extern Employee eligibleEmp[20];

}
#endif // !SDDS_BIRTHDATE_H
