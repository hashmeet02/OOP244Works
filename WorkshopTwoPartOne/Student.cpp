//***************************************************
//                    W2P1
//Hashmeet Singh Saini
//153070214
//hsaini28@myseneca.ca
//OOP244 - NFF
//I have done all the coding by myself and only copied 
//the code that my professor provided to complete my 
//workshops and assignments.
//***************************************************

#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "File.h"
#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;
namespace sdds {
	Student* students = nullptr;
	int noOfStudents;


	void sort() {
		int i, j;
		Student temp;
		for (i = noOfStudents - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (students[j].m_grade > students[j + 1].m_grade) {
					temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}
			}
		}
	}
	bool load(Student& stu) {
		bool testName = false, testSNo = false, testGrade = false, flag = false;
		char temp[128];
		int length;
		testName = read(temp);
		testSNo = read(stu.m_studentNumber);
		testGrade = read(stu.m_grade);
		if (testName && testSNo && testGrade) {
			length = strlen(temp) + 1;
			stu.m_name = new char[length];
			strcpy(stu.m_name, temp);
			flag = true;
		}
		else {
			flag = false;
		}
		return flag;
	}
	bool load(const char* datafile) {
		bool test = false;
		bool totalTest = false;
		int i = 0;
		openFile(datafile);
		noOfStudents = noOfRecords();
		students = new Student[noOfStudents];
		

		for (i = 0; i < noOfStudents; i++) {
			test = load(students[i]);
			if (!test) {
				cout << "error: incorrect number of records read; the data is possibly corrupted." << endl;
				totalTest = false;
			}
			else {
				
				totalTest = true;
			}
		}
		closeFile();
		return totalTest;
	}
	void display(const Student& stu) {
		cout << stu.m_name << ", " << stu.m_studentNumber << ": " << stu.m_grade << endl;
	}
	void display() {
		int i = 0;
		sort();
		for (i = 0; i < noOfStudents; i++) {
			cout << i + 1 << ": ";
			display(students[i]);
		}
	}
	void deallocateMemory() {
		int i = 0;
		for (i = 0; i < noOfStudents; i++) {
			delete[] students[i].m_name;
			students[i].m_name = nullptr;
		}
		delete[] students;
		students = nullptr;
	}
}



