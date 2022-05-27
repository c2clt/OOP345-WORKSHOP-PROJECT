/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 5: Functions and Error Handling
// File:  Book.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/22/2020
// Description: definition of Book Module
***********************************************************************/
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include <iostream>

namespace sdds {
	class Book {
		std::string m_author = "";
		std::string m_title = "";
		std::string m_country = "";
		size_t m_year = 0u;
		double m_price = 0.0f;
		std::string m_description = "";

		void trim(std::string& str) const;
	public:
		Book() { }
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& b);

		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_description);
		}
	};
 }
#endif