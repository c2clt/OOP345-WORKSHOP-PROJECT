/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 4: Containers
// File:  Reservation.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/16/2020
// Description: definition of Reservation Module
***********************************************************************/

#ifndef SDDS_RESERVATION_H__
#define SDDS_RESERVATION_H__

#include <iostream>

namespace sdds {
	class Reservation {
		std::string m_id = "";
		std::string m_name = "";
	    std::string m_email = "";
		size_t m_party = 0u;
		size_t m_day = 0u;
		size_t m_hour = 0u;

		void trim(std::string& str) const;
	public:
		Reservation() { }
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation res);
	};
}
#endif