/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 4: Containers
// File:  Restaurant.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/16/2020
// Description: implementation of Restaurant Module
***********************************************************************/
#include "Restaurant.h"

namespace sdds {
	
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		if (cnt > 0) {
			m_cnt = cnt;
			m_res = new Reservation[m_cnt];
			for (size_t i = 0; i < m_cnt; i++) {
				m_res[i] = *reservations[i];
			}
		}
		else {
			m_res = nullptr;
			m_cnt = 0;
		}
	}

	Restaurant::Restaurant(const Restaurant& src) {
		if (src.m_res != nullptr) {
			m_cnt = src.m_cnt;
			m_res = new Reservation[m_cnt];
			for (size_t i = 0; i < m_cnt; i++) {
				m_res[i] = src.m_res[i];
			}
		}
		else {
			m_cnt = 0;
			m_res = nullptr;
		}
	}

	Restaurant::Restaurant(Restaurant&& src) {
		if (src.m_res != nullptr) {
			m_cnt = src.m_cnt;
			m_res = src.m_res;
			src.m_cnt = 0;
			src.m_res = nullptr;
		}
		else {
			m_cnt = 0;
			m_res = nullptr;
		}
	}

	size_t Restaurant::size() const {
		return m_cnt;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant" << std::endl;
		os << "--------------------------" << std::endl;
		if (restaurant.m_res == nullptr) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < restaurant.m_cnt; i++) {
				os << restaurant.m_res[i];
			}
		}
		os << "--------------------------" << std::endl;

		return os;
	}

	Restaurant::~Restaurant() {
		delete[] m_res;
		m_res = nullptr;
	}
}