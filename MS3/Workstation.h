#pragma once
/***********************************************************************
// Name: Jingmin (Jessica) Zhou
// Seneca Student ID: 119766194
// Seneca email: jzhou175@myseneca.ca
// Date of completion: July 20th 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// OOP345 Project: Milestone 3
// File:  Workstation.h
// Description: definition of Workstation Module
***********************************************************************/

#ifndef SDDS_WORKSTATION_H__
#define SDDS_WORKSTATION_H__

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

class Workstation : public Station {
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation; // pointer to the next station on the assembly line
public:
	Workstation(const std::string& record);
	Workstation(const Workstation& src) = delete;
	Workstation& operator=(const Workstation& src) = delete;
	void runProcess(std::ostream& os);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream& os) const;
	Workstation& operator+=(CustomerOrder&& customerOrder);
};

#endif
