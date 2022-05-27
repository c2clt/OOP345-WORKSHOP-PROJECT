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
#include "Reservation.h"

namespace sdds {

	void Reservation::trim(std::string& str) const {
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
	
	/*void Reservation::trim(std::string& str) const {
		size_t pos = 0u;
		if (!str.empty()) {
			while ((pos = str.find(' ', pos)) != std::string::npos) {
				str.erase(pos, 1);
			}
		}
	}

	Reservation::Reservation(const std::string& res) {
		std::string tmpRes = res;
		trim(tmpRes);
		size_t posS = 0u;
		size_t posE = tmpRes.find(':');
		m_id = tmpRes.substr(posS, posE - posS);
		
		posS = posE + 1;
		posE = tmpRes.find(',', posS);
		m_name = tmpRes.substr(posS, posE - posS);

		posS = posE + 1;
		posE = tmpRes.find(',', posS);
		m_email = tmpRes.substr(posS, posE - posS);

		posS = posE + 1;
		posE = tmpRes.find(',', posS);
		m_party = std::stoi(tmpRes.substr(posS, posE - posS));

		posS = posE + 1;
	    posE = tmpRes.find(',', posS);
		m_day = std::stoi(tmpRes.substr(posS, posE - posS));

		posS = posE + 1;
		posE = tmpRes.find(',', posS);
		m_hour = std::stoi(tmpRes.substr(posS, posE - posS));

	}*/

	std::ostream& operator<<(std::ostream& os, const Reservation res) {
		std::string emailTmp = "<" + res.m_email + ">";
		os << "Reservation " << res.m_id << ": "
			<< std::setw(10) << std::right << res.m_name << "  "
			<< std::setw(24) << std::left << emailTmp << std::right;

		if (res.m_hour >= 6 && res.m_hour <= 9) {
			os << "Breakfast";
		}
		else if (res.m_hour >= 11 && res.m_hour <= 15) {
			os << "Lunch";
		}
		else if (res.m_hour >= 17 && res.m_hour <= 21) {
			os << "Dinner";
		}
		else {
			os << "Drinks";
		}

		os << " on day " << res.m_day << " @ "
			<< res.m_hour << ":00 for "
			<< res.m_party << " people." << std::endl;

		return os;
	}
}