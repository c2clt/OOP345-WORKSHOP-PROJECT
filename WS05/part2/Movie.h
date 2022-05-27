/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 5: Functions and Error Handling
// File:  Movie.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/22/2020
// Description: definition of Movie Module
***********************************************************************/

#ifndef SDDS_MOVIE_H__
#define SDDS_MOVIE_H__

#include <iostream>
namespace sdds {
	class Movie {
		std::string m_title = "";
		size_t m_year = 0u;
		std::string m_description = "";

		void trim(std::string& str) const;
	public:
		Movie() {}
		const std::string& title() const;
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& os, const Movie& m);

		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
	};
}
#endif