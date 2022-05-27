/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 4: Containers
// File:  Restaurant.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/18/2020
// Description: definition of Restaurant Module
***********************************************************************/
#ifndef SDDS_RESTAURANT_H__
#define SDDS_RESTAURANT_H__

#include <iostream>
#include "Reservation.h"

namespace sdds {
	class Restaurant {
		Reservation* m_res = nullptr;
		size_t m_cnt = 0u;
	public:
		Restaurant() {}
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& src);
		Restaurant(Restaurant&& src);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
		virtual ~Restaurant();
	};
	
}
#endif