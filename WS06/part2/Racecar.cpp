/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 6: STL Containers
// File:  Racecar.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/29/2020
// Description: implementation of Racecar Module
***********************************************************************/

#include <string>
#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in) {
		std::string booster = "";
		getline(in, booster);
		
		if (stod(booster) > 0 && stod(booster) < 1) {
			m_booster = stod(booster);
		}		
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return (Car::topSpeed()) * (1 + m_booster);
	}
}