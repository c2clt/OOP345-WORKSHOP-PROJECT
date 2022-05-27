/***********************************************************************
// Name: Jingmin (Jessica) Zhou
// Seneca Student ID: 119766194
// Seneca email: jzhou175@myseneca.ca
// Date of completion: July 16th 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// OOP345 Project: Milestone 2
// File:  Station.h
// Description: definition of Station Module
***********************************************************************/
#ifndef SDDS_STATION_H__
#define SDDS_STATION_H__

#include "Utilities.h"

const size_t WIDTH_ID = 3u;
const size_t WIDTH_SERIAL = 6u;

class Station {
	unsigned int m_id;
	std::string m_name;
	std::string m_desc;
	unsigned int m_serialNumber;
	unsigned int m_quantity;

	static size_t m_widthField;
	static size_t id_generator;
public:
	Station(const std::string str);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

#endif