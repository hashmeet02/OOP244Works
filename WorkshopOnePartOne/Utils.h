#ifndef SDDS_UTILS_H // replace with relevant names
#define SDDS_UTILS_H
namespace sdds {
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);

}

// Your header file content goes here

#endif