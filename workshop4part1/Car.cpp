//*******************************************************************
//Reflection Workshop 4 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : June 07, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
#include "Car.h"
#include "Utils.h"


using namespace std;
namespace sdds {

	//default constructor
	Car::Car() {
		resetInfo();
	}

	//constructor with arguments
	Car::Car(const char* type,
		const char* brand,
		const char* model,
		int year,
		int code,
		double price) {
		bool typeF = false, brandF = false, modelF = false, yearF = false, codeF = false, priceF = false;
		
		if (type && type[0]) {
			typeF = true;
		}
		if (brand && brand[0]) {
			brandF = true;
		}
		if (model && model[0]) {
			modelF = true;
		}
		if (year >= 1990) {
			yearF = true;
		}
		if (code > 99 && code < 1000) {
			codeF = true;
		}
		if (price > 0) {
			priceF = true;
		}
		if ((typeF && brandF && modelF && yearF && codeF && priceF)) {
			m_type = U.aloCpy(type);
			m_brand = U.aloCpy(brand);
			m_model = U.aloCpy(model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else {
			resetInfo();
		}
	}

	//deconstructor
	Car::~Car() {
		deallocate();
	}

	//resets the object
	void Car::resetInfo() {
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}

	//sets the object to given values
	Car& Car::setInfo(const char* type,
		const char* brand,
		const char* model,
		int year,
		int code,
		double price) {
		deallocate();
		bool typeF = false, brandF = false, modelF = false, yearF = false, codeF = false, priceF = false;
		if (type && type[0]) {
			typeF = true;
		}
		if (brand && brand[0]) {
			brandF = true;
		}
		if (model && model[0]) {
			modelF = true;
		}
		if (year >= 1990) {
			yearF = true;
		}
		if (code > 99 && code < 1000) {
			codeF = true;
		}
		if (price > 0) {
			priceF = true;
		}
		if ((typeF && brandF && modelF && yearF && codeF && priceF)) {
			m_type = U.aloCpy(type);
			m_brand = U.aloCpy(brand);
			m_model = U.aloCpy(model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else {
			resetInfo();
		}
		return *this;
	}

	//displays the stored data for object
	void Car::printInfo() const {
		cout << "| ";
		cout.setf(ios::left);
		cout.width(11);
		cout << m_type << "| ";
		cout.width(17);
		cout << m_brand << "| ";
		cout.width(17);
		cout << m_model << "| ";
		cout.width(5);
		cout << m_year << "| ";
		cout.unsetf(ios::left);
		cout.setf(ios::right);
		cout.width(4);
		cout << m_code << " |";
		cout.width(10);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << m_price << " |";
		cout.unsetf(ios::right);
		cout << endl;
	}

	//checks for invalid objects
	bool Car::isValid() const
	{
		bool typeF = false, brandF = false, modelF = false, yearF = false, codeF = false, priceF = false;
		if (m_type && m_type[0]) {
			typeF = true;
		}
		if (m_brand && m_brand[0]) {
			brandF = true;
		}
		if (m_model && m_model[0]) {
			modelF = true;
		}
		if (m_year >= 1990) {
			yearF = true;
		}
		if (m_code > 99 && m_code < 1000) {
			codeF = true;
		}
		if (m_price > 0) {
			priceF = true;
		}
		if ((typeF && brandF && modelF && yearF && codeF && priceF)) return true;
		else return false;
	}

	//checks for duplicate objects
	bool Car::isSimilarTo(const Car& car) const
	{
		bool typeF = false, brandF = false, modelF = false, yearF = false;
		if (m_type == car.m_type) {
			typeF = true;
		}
		if (m_brand == car.m_brand) {
			brandF = true;
		}
		if (m_model == car.m_model) {
			modelF = true;
		}
		if (m_year == car.m_year) {
			yearF = true;
		}
		if (typeF && brandF && modelF && yearF) return true;
		else return false;
	}

	//deallocates all the dynamically allocated memory
	void Car::deallocate() {
		delete[] m_type;
		m_type = nullptr;
		delete[] m_brand;
		m_brand = nullptr;
		delete[] m_model;
		m_model = nullptr;
	}

	//checks for similar objects in the array
	bool has_similar(const Car car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					return true;
				}
			}
		}
		return false;
	}

	//checks for inavlid objects in the array
	bool has_invalid(const Car car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++) {
			if (!car[i].isValid()) {
				return true;
			}
		}
		return false;
	}

	//displays all the records in inventory
	void print(const Car car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++) {
			if (car[i].isValid()) {
				car[i].printInfo();
			}
		}
	}



}