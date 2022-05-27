/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 6: STL Containers
// File:  Car.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/29/2020
// Description: definition of Car Module
***********************************************************************/
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

#include <iostream>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
		std::string m_maker  = "";
		std::string m_condition = "";
		double m_topSpeed = 0.0f;

		void trim(std::string& str) const;
		bool isInteger(std::string& str) const;
	public:
		Car(std::istream& is = std::cin);
		std::string condition() const;
		double topSpeed() const;
		virtual void display(std::ostream& out = std::cout) const;
	};
}

#endif