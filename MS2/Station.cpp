/***********************************************************************
// Name: Jingmin (Jessica) Zhou
// Seneca Student ID: 119766194
// Seneca email: jzhou175@myseneca.ca
// Date of completion: July 16th 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// OOP345 Project: Milestone 2
// File:  Station.cpp
// Description: implementation of Station Module
***********************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

size_t Station::m_widthField = 0u;
size_t Station::id_generator = 0u;

Station::Station(const std::string& str) {
	Utilities util;
	size_t next_pos = 0;
	bool more = false;

	m_id = ++id_generator;

	if (str.empty()) {
		m_name = "";
		m_serialNumber = 0;
		m_quantity = 0;
	}
	else {
		m_name = util.extractToken(str, next_pos, more);

		if (more) {
			std::string tmpSerial = util.extractToken(str, next_pos, more);
			m_serialNumber = stoi(tmpSerial);
		}

		if (more) {
			std::string tmpQty = util.extractToken(str, next_pos, more);
			m_quantity = stoi(tmpQty);
		}

		m_widthField = m_widthField > util.getFieldWidth() ? m_widthField : util.getFieldWidth();

		if (more) {
			m_desc = util.extractToken(str, next_pos, more);
		}		
	}
}

const std::string& Station::getItemName() const {
	return m_name;
}
	
unsigned int Station::getNextSerialNumber() {
	return m_serialNumber++;
}

unsigned int Station::getQuantity() const {
	return m_quantity;
}

void Station::updateQuantity() {
	if (m_quantity > 0) {
		m_quantity--;
	}
}

void Station::display(std::ostream& os, bool full) const {
	// [ID] Item: NAME [SERIAL]
	os << "[" << std::right << std::setw(WIDTH_ID) << std::setfill('0') << m_id << std::setfill(' ') << "] ";
	os << "Item: " << std::left << std::setw(m_widthField) << m_name;
	os << " [" << std::right << std::setw(WIDTH_SERIAL) << std::setfill('0') << m_serialNumber << std::setfill(' ') << "]";
	if (full) {
		// [ID] Item: NAME [SERIAL] Quantity: QTY Description: DESCRIPTION		
		os << " Quantity: " << std::left << std::setw(m_widthField) << m_quantity;
		os << " Description: " << m_desc;		
	}	
	os << std::endl;	
}
