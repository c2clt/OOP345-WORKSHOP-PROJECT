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
#include "Car.h"
#include "Utilities.h"

namespace sdds {
	Car::Car(std::istream& is) {
		std::string str = "";
		std::getline(is, str);
		
		size_t posS = 0u;
		size_t posE = str.find(',', posS);

		posS = posE + 1;
		posE = str.find(',', posS);
		trim(m_maker = str.substr(posS, posE - posS));
			
		posS = posE + 1;
		posE = str.find(',', posS);
		std::string condition = str.substr(posS, posE - posS);
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

		posS = posE + 1;
		posE = str.find(',', posS);
		std::string top_Speed = str.substr(posS, posE - posS);
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
			<< " | " << std::left << std::setw(6) << m_condition
			<< std::right << " | " << std::setw(6) << std::fixed << std::setprecision(2) 
			<< m_topSpeed << " |" << std::endl;
	}
}