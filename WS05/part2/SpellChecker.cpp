/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 5: Functions and Error Handling
// File:  SpellChecker.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/22/2020
// Description: implementation of SpellChecker Module
***********************************************************************/
#include <fstream>
#include "SpellChecker.h"

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file.is_open()) {
			throw "Bad file name!";
		}

		for (size_t i = 0; i < MAXSIZE; i++) {
			file >> m_badWords[i];
			file >> m_goodWords[i];
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		for (size_t i = 0; i < MAXSIZE; i++) {
			size_t pos = text.find(m_badWords[i]);
			while (pos != std::string::npos) {
				text.replace(pos, m_badWords[i].size(), m_goodWords[i]);
				pos = text.find(m_badWords[i]);
			}
		}
	}
}