/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 6: STL Containers
// File:  Utilities.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/29/2020
// Description: implementation of Utilities Module
***********************************************************************/

#include <sstream>
#include "Utilities.h"

namespace sdds {
	
	Vehicle* createInstance(std::istream& in) {
		Vehicle* vp = nullptr;
		std::string str = "";
		char tag = ' ';
		std::getline(in, str);
		std::stringstream ss(str);
		
		ss >> tag;
		ss.ignore(1000, ',');
		if (tag == 'c' || tag == 'C') {
			vp = new Car(ss);
		}

		return vp;
	}
}