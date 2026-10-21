#ifndef ADDRESS_H
#define ADDRESS_H
#include <string> 

class Address { 
	private: 
		std::string street; 
		std::string city;
		std::string state; 
		std::string zip; 
	public:
		Address(); 
		void init(std::string s, std::string c, std::string st, std::string z); 
		void printAddress(); 
}; 
#endif
