/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 5: Functions and Error Handling
// File:  Movie.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/22/2020
// Description: implementation of Movie Module
***********************************************************************/

#include <string>
#include <iomanip>
#include "Movie.h"

namespace sdds {

	void Movie::trim(std::string& str) const {
		if (!str.empty())
		{
			str.erase(0, str.find_first_not_of(" "));
			str.erase(str.find_last_not_of(" ") + 1);
		}	
	}

	const std::string& Movie::title() const {
		return m_title;
	}

	Movie::Movie(const std::string& strMovie) {
		size_t pS = 0u;
		size_t pE = strMovie.find(',');
		trim(m_title = strMovie.substr(pS, pE - pS));

		pS = pE + 1;
		pE = strMovie.find(',', pS);
		m_year = std::stoi(strMovie.substr(pS, pE - pS));

		pS = pE + 1;
		trim(m_description = strMovie.substr(pS));
	}

	std::ostream& operator<<(std::ostream& os, const Movie& m) {
		os << std::setw(40) << std::right << m.m_title << " | "
			<< std::setw(4) << std::right << m.m_year << " | "
			<< std::left << m.m_description << std::endl;

		return os;
	}
}