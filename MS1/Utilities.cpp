/***********************************************************************
// Name: Jingmin (Jessica) Zhou
// Seneca Student ID: 119766194
// Seneca email: jzhou175@myseneca.ca
// Date of completion: July 7th 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// OOP345 Project: Milestone 1
// File:  Utilities.cpp
// Description: implementation of Utilities Module
***********************************************************************/
#include <string>
#include "Utilities.h"

char Utilities::m_delimiter = '\0';

void Utilities::setFieldWidth(size_t newWidth) {
	if (newWidth > 1u) {
		m_widthField = newWidth;
	}
	else {
		m_widthField = 1u;
	}
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	std::string token = "";

	if (next_pos <= str.length()) {
		size_t pos = str.find(m_delimiter, next_pos);
		if (pos != std::string::npos) {
			token = str.substr(next_pos, pos - next_pos);
			next_pos = pos + 1;
		}
		else {
			token = str.substr(next_pos);
			next_pos = str.length() + 1;
		}

		m_widthField = m_widthField > token.length() ? m_widthField : token.length();

		if (token.empty() && (next_pos != str.length() + 1)) {
			more = false;
			throw "There is no token extracted";
		}

		more = next_pos <= str.length();
	}

	return token;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}