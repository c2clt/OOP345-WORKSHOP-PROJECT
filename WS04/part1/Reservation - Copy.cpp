/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 4: Containers
// File:  Reservation.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/16/2020
// Description: implementation of Reservation Module
***********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Reservation.h"

namespace sdds {
	
	void Reservation::trim(std::string str) const {
		size_t i;
		for (i = 0; i < str.length() && str[i] == ' '; ++i);
		str = str.substr(i);
		for (i = str.length() - 1; i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}

	Reservation::Reservation(const std::string& res) {
		size_t posS = 0u;
		size_t posE = res.find(':');
		trim(m_id = res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = res.find(',', posS);
		trim(m_name = res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = res.find(',', posS);
		trim(m_email = res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = res.find(',', posS);
		m_party = std::stoi(res.substr(posS, posE - posS));

		posS = posE + 1;
	    posE = res.find(',', posS);
		m_day = std::stoi(res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = res.find(',', posS);
		m_hour = std::stoi(res.substr(posS, posE - posS));

	}
	/*Reservation::Reservation(const std::string& res) {
		std::istringstream  ss(res);
		std::string id = "";
		std::getline(ss, id, ':');
		std::istringstream ss1(id);
		ss1 >> m_id;
		std::string val[5];
		std::string tmp;
		int idx = 0;
		while (std::getline(ss, tmp, ',')) {
			std::istringstream ss2(tmp);
			ss2 >> val[idx++];
		}
		m_name = val[0];
		m_email = val[1];
		m_party = stoi(val[2]);
		m_day = stoi(val[3]);
		m_hour = stoi(val[4]);
	}*/

	std::ostream& Reservation::display(std::ostream& os) const {
		std::string email = "<" + m_email + ">";
		os << "Reservation " << m_id << ": "
			<< std::setw(10) << std::right << m_name << " "
			<< std::setw(20) << std::left << email << std::right;

		if (m_hour >= 6 && m_hour <= 9) {
			os << "Breakfast";
		}
		else if (m_hour >= 11 && m_hour <= 15) {
			os << "Lunch";
		}
		else if (m_hour >= 17 && m_hour <= 21) {
			os << "Dinner";
		}
		else {
			os << "Drinks";
		}

		os << " on day " << m_day << " @ " 
			<< m_hour << ":00 for " 
			<< m_party << " people." << std::endl;

		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Reservation res) {
		return res.display(os);
	}
}