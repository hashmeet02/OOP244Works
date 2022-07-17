//*******************************************************************
//Reflection Workshop 6 Part 1
//Name:			Hashmeet Singh Saini
//Seneca ID : hsaini28
//Student No. : 153070214
//Date : July 5 , 2022
//I have done all the coding by myself and only copied the code that
//my professor provided to complete my workshops and assignments.
//*******************************************************************

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }

   Numbers::Numbers(const Numbers& toCopy)
   {
       setEmpty();
       m_isOriginal = false;
       *this=toCopy;
   }

   Numbers& Numbers::operator=(const Numbers& toAssing)
   {
       if (this != &toAssing) { // prevent self assignment
           delete[] m_numbers;
           m_numCount = toAssing.m_numCount;
           if (!toAssing.isEmpty()) {
               m_numbers = new double[m_numCount];
               for (int i = 0; i < m_numCount; i++) {
                   m_numbers[i] = toAssing.m_numbers[i];
               }
           }
           else m_numbers = nullptr;
       }
       return *this;
   }

   int Numbers::numberCount() const
   {
       int counter = 0;
       char i;
       bool flag = 0;
       std::ifstream f(m_filename);
       if (f.is_open()) {
           while (f.good()) {
               f.get(i);
               if (i == '\n' && flag==0) {
                   flag = 1;
                   counter++;
               }
               else {
                   flag = 0;
               }
           }
       }
       return counter;
   }

   bool Numbers::load()
   {
       int i = 0;
       double c = 0;
       if (m_numCount > 0) {
           m_numbers = new double[m_numCount];
           std::ifstream f(m_filename);
           while (f >> c)
           {
               m_numbers[i]=c;
               i++;
           }
       }
       return i==m_numCount;
   }

   void Numbers::save()
   {
       if (m_isOriginal && !(isEmpty())) {
           std::ofstream f(m_filename);
           for (int i = 0; i < m_numCount; i++) {
               f << m_numbers[i] << std::endl;
           }
       }
   }

   Numbers& Numbers::operator+=(const double ro)
   {
       double* temp{};
       temp = new double[this->m_numCount + 1];
       for (int i = 0; i < m_numCount; i++) {
           temp[i] = m_numbers[i];
       }
       temp[m_numCount] = ro;
       delete[] m_numbers;
       m_numbers = nullptr;
       m_numbers = temp;
       m_numCount += 1;
       sort();
       return *this;
   }

   std::ostream& Numbers::display(std::ostream& ostr) const
   {
       if (isEmpty()) {
           ostr << "Empty list";
       }
       else {
           ostr << "=========================" << endl;
           if (m_isOriginal) {
               ostr << m_filename << endl;
           }
           else {
               ostr << "*** COPY ***" << endl;
           }
           for (int i = 0; i < m_numCount; i++) {
               ostr << m_numbers[i];
               if (i < m_numCount - 1) {
                   ostr << ", ";
               }
               else {
                   ostr << endl;
               }
           }
           ostr << "-------------------------"<<endl;
           ostr << "Total of " << m_numCount << " number(s)"<<endl;
           ostr << "Largest number:  ";
           ostr<< max() << endl;
           ostr << "Smallest number: " << min()<<endl;
           ostr << "Average :        ";
           ostr << average() << endl;
           ostr << "=========================";

       }
       return ostr;      
   }

   std::ostream& operator<<(std::ostream& os, const Numbers& N)
   {
       return N.display(os);
   }
   istream& operator>>(istream& istr, Numbers& N) {
       double value=0.0;
       istr >> value;
       N += value;
       return istr;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }


   
}
