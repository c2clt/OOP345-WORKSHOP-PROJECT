/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 6: STL Containers
// File:  Autoshop.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/29/2020
// Description: implementation of Autoshop Module
***********************************************************************/
#include "Autoshop.h"

namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (size_t i = 0; i < m_vehicles.size(); i++) {
			m_vehicles[i]->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}
	Autoshop::~Autoshop() {
		for (size_t i = 0u; i < m_vehicles.size(); i++) {
			delete m_vehicles[i];
			m_vehicles[i] = nullptr;
		}
	}
}