#ifndef STUDENT_H
#define STUDENT_H 
#include <string> 
#include "address.h"
#include "date.h" 

class Student { 
	private: 
		std::string studentString; 
		std::string firstName; 
		std::string lastName; 

		Date* dob; 
		Date* expectedGrad; 
		Address* address; 
		int CreditHours; 

	public: 
		Student(); 
		~Student(); 

		void init(std::string s); 
		void printStudent(); 
		std::string getFirstName(); 
		std::string getLastName(); 
		std::string getLastFirst();
		int getCreditHours(); 
};

#endif
