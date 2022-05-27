/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 6: STL Containers
// File:  Racecar.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/29/2020
// Description: definition of Racecar Module
***********************************************************************/

#ifndef SDDS_RACECAR_H__
#define SDDS_RACECAR_H__

#include "Car.h"

namespace sdds {
	class Racecar : public Car {
		double m_booster = 0.0f;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out = std::cout) const;
		double topSpeed() const;
	};
}
#endif