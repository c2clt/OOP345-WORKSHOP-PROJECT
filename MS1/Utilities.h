/***********************************************************************
// Name: Jingmin (Jessica) Zhou
// Seneca Student ID: 119766194
// Seneca email: jzhou175@myseneca.ca
// Date of completion: July 7th 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// OOP345 Project: Milestone 1
// File:  Utilities.h
// Description: definition of Utilities Module
***********************************************************************/
#ifndef SDDS_UTILITIES_H__
#define SDDS_UTILITIES_H__

#include <iostream>

class Utilities {
	size_t m_widthField = 1u;
	static char m_delimiter;
public:
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
}; 

#endif