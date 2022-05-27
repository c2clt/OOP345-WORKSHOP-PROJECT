#pragma once
/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 6: STL Containers
// File:  Autoshop.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/29/2020
// Description: definition of Autoshop Module
***********************************************************************/
#ifndef SDDS_AUTOSHOP_H__
#define SDDS_AUTOSHOP_H__

#include <vector>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
	};
}

#endif