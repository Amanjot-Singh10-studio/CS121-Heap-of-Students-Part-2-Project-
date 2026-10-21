#include <iostream>
#include <sstream> 
#include <string>
#include "student.h"

Student::Student() { 
	dob = new Date(); 
	expectedGrad = new Date(); 
	address = new Address(); 
	CreditHours = 0; 
} 
Student::~Student() { 
	delete dob; 
	delete expectedGrad; 
	delete address; 
} 

void Student::init(std::string s) { 
	studentString = s; 
	std::stringstream ss(s); 

	std::string street; 
	std::string city; 
	std::string state; 
	std::string zip; 
	std::string dobString; 
	std::string gradString; 

	getline(ss, firstName, ',');
	getline(ss, lastName, ',');
	getline(ss, street, ',');
	getline(ss, city, ',');
	getline(ss, state, ',');
	getline(ss, zip, ',');
	getline(ss, dobString, ',');
	getline(ss, gradString, ',');

	ss >> CreditHours; 

	address->init(street, city, state, zip);
	dob->init(dobString);
	expectedGrad->init(gradString); 
} 

void Student::printStudent() { 
	std::cout << firstName << " " << lastName << std::endl; 
	address->printAddress(); 
	std::cout << "DOB: "; 
	dob->printDate(); 
	std::cout << "Grad: "; 
	expectedGrad->printDate(); 
	std::cout << "Credits: " << CreditHours << std::endl; 
} 

std::string Student::getFirstName() { 
	return firstName; 
}
std::string Student::getLastName() { 
	return lastName; 
}
std::string Student::getLastFirst() { 
	return lastName + ", " + firstName; 
} 
int Student::getCreditHours() { 
	return CreditHours; 
} 
