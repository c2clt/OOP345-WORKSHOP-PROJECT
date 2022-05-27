/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 5: Functions and Error Handling
// File:  Book.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/22/2020
// Description: implementation of Book Module
***********************************************************************/

#include <string>
#include <iomanip>
#include "Book.h"

namespace sdds {
	void Book::trim(std::string& str) const {
		if (!str.empty())
		{
			str.erase(0, str.find_first_not_of(" "));
			str.erase(str.find_last_not_of(" ") + 1);
		}		
	}

	const std::string& Book::title() const {
		return m_title;
	}

	const std::string& Book::country() const {
		return m_country;
	}

	const size_t& Book::year() const {
		return m_year;
	}
	double& Book::price() {
		return m_price;
	}

	Book::Book(const std::string& strBook) {
		size_t pS = 0u;
		size_t pE = strBook.find(',');
		trim(m_author = strBook.substr(pS, pE - pS));

		pS = pE + 1;
		pE = strBook.find(',', pS);
		trim(m_title = strBook.substr(pS, pE - pS));

		pS = pE + 1;
		pE = strBook.find(',', pS);
		trim(m_country = strBook.substr(pS, pE - pS));

		pS = pE + 1;
		pE = strBook.find(',', pS);
		m_price = std::stod(strBook.substr(pS, pE - pS));

		pS = pE + 1;
		pE = strBook.find(',', pS);
		m_year = std::stoi(strBook.substr(pS, pE - pS));

		pS = pE + 1;
		trim(m_description = strBook.substr(pS));
	}

	std::ostream& operator<<(std::ostream& os, const Book& b) {
		os << std::setw(20) << std::right << b.m_author << " | "
			<< std::setw(22) << std::right << b.m_title << " | "
			<< std::setw(5) << std::right << b.m_country << " | "
			<< std::setw(4) << std::right << b.m_year << " | "
			<< std::setw(6) << std::right << std::setiosflags(std::ios::fixed) << std::setprecision(2) << b.m_price << " | "
			<< std::left << b.m_description << std::endl;

		return os;
	}
}