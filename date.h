#ifndef DATE_H
#define DATE_H
#include <string> 

class Date { 
	private: 
		std::string dateString; 
		int month; 
		int day; 
		int year; 
	public: 
		Date(); 
		void init(std::string d); 
		void printDate(); 
	}; 
#endif
