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
#include <iostream>
#include <cstdio>
#include "File.h"

using namespace std;
namespace sdds {
   FILE* fptr=nullptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   bool read(char name[]) {
       int test=fscanf(fptr, "%[^,],", name);
       return test==1;
   }
   bool read(int& sNo) {
       int test = fscanf(fptr, "%d,", &sNo);
       return test==1;
   }
   bool read(char& grade) {
       int test = fscanf(fptr, "%c\n", &grade);
       return test==1;
   }

}