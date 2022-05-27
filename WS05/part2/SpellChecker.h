/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 5: Functions and Error Handling
// File:  SpellChecker.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/22/2020
// Description: definition of SpellChecker Module
***********************************************************************/

#ifndef SDDS_SPELLCHECKER_H__
#define SDDS_SPELLCHECKER_H__

namespace sdds {
	const size_t MAXSIZE = 5;
	class SpellChecker {		
		std::string m_badWords[MAXSIZE] = { "" };
		std::string m_goodWords[MAXSIZE] = { "" };
	public:
		SpellChecker() { }
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
	
}
#endif