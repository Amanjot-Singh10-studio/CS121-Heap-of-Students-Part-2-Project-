#include <iostream>
#include <string> 
#include <sstream>
#include "date.h" 
Date::Date() { 
	     month = 0; 
	     day = 0; 
	     year = 0; 
} 

void Date::init(std::string d) { 
	dateString = d; 
	char slash; 
	std::stringstream ss(d); 
	ss >> month; 
	ss >> slash; 
	ss >> day; 
	ss >> slash; 
	ss >> year; 
} 

void Date::printDate() { 
	std::string months[12] = {" Janurary", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" } ; 
	if (month >= 1 && month <= 12) { 
		std::cout << months[month - 1]; 
	} 
	std::cout << " " << day << ", " << year << std::endl; 
} 

