//*******************************************************************
//Reflection Workshop 4 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : June 07, 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds {

	//class Car definition
	class Car {
		char* m_type{};
		char* m_brand{};
		char* m_model{};
		int m_year{};
		int m_code{};
		double m_price{};
		void resetInfo();
		void deallocate();

	public:

		//default constructor
		Car();

		//constructor with arguments
		Car(const char* type,
			const char* brand,
			const char* model,
			int year = 2022,
			int code = 100,
			double price = 1.0);
	//deconstructor
		~Car();

		Car& setInfo(const char* type,
			const char* brand,
			const char* model,
			int year,
			int code,
			double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const Car& car) const;

	};
	bool has_similar(const Car car[], const int num_cars);
	bool has_invalid(const Car car[], const int num_cars);
	void print(const Car car[], const int num_cars);

}
#endif // !SDDS_CAR_H
