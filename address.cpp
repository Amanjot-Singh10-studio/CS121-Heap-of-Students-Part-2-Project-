#include <iostream> 
#include "address.h" 

Address::Address() { 
}
	void Address::init(std::string s, std::string c, std::string st, std::string z) {
		street = s; 
	       	city = c; 
		state = st; 
		zip = z; 	
	} 

	void Address::printAddress() { 
		std::cout << street << std::endl;
		std::cout << city << " " << state << ", " << zip << std::endl; 
} 
