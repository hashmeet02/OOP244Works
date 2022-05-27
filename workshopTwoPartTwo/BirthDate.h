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
		struct Date* dates;
	};

	bool beginSearch(const char* filename);
	bool openFile(const char* filename);
	int noOfRecords();
	bool loadData(Employee& emp);
	bool readBirthDate(int month);
	void sort();
	void displayBirthdays();
	void deallocate();
	void endSearch();
	extern Employee* employees;
	extern Employee* eligibleEmp;

}
#endif // !SDDS_BIRTHDATE_H
