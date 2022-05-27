/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 6: STL Containers
// File:  Car.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/29/2020
// Description: implementation of Car Module
***********************************************************************/

#include <iomanip>
#include <cctype>
#include <string>
#include "Car.h"
#include "Utilities.h"

namespace sdds {

	void Car::trim(std::string& str) const {
		if (!str.empty())
		{
			str.erase(0, str.find_first_not_of(" "));
			str.erase(str.find_last_not_of(" ") + 1);
		}
	}

	bool Car::isInteger(std::string& str) const {
		bool res = true;
		for (size_t i = 0u; i < str.size() && res; i++) {
			if (!isdigit(str[i])) {
				res = false;
			}
		}

		return res;
	} 

	Car::Car(std::istream& is) {
		
		getline(is, m_maker, ',');
		trim(m_maker);
		
		std::string condition = "";
		getline(is, condition, ',');
		trim(condition);
		if (condition == "n") {
			m_condition = "new";
		}
		else if (condition == "u") {
			m_condition = "used";
		}
		else if (condition == "b") {
			m_condition = "broken";
		}

		std::string top_Speed = "";
		getline(is, top_Speed, ',');
		trim(top_Speed);
		if (isInteger(top_Speed)) {
			m_topSpeed = stod(top_Speed);
		}
	
	}

	std::string Car::condition() const {
		return m_condition;
	}

	double Car::topSpeed() const {
		return m_topSpeed;
	}

	void Car::display(std::ostream& out) const {
		
		out << "| " << std::setw(10) << m_maker
			<< " | " << std::left << std::setw(6) << condition()
			<< std::right << " | " << std::setw(6) << std::fixed << std::setprecision(2) 
			<< topSpeed() << " |";
	}
}