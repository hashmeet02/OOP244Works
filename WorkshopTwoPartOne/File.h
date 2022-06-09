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

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   //bool read();
   bool read(char name[]);
   bool read(int& sNo);
   bool read(char& grade);
  
}
#endif // !SDDS_FILE_H_
