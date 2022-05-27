/***********************************************************************
// Name: Jingmin (Jessica) Zhou
// Seneca Student ID: 119766194
// Seneca email: jzhou175@myseneca.ca
// Date of completion: July 20th 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// OOP345 Project: Milestone 3
// File:  Workstation.cpp
// Description: implementation of Workstation Module
***********************************************************************/
#include "Workstation.h"

Workstation::Workstation(const std::string& record) : Station(record) {
	m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		m_orders.front().fillItem(*this, os);
	}
}

bool Workstation::moveOrder() {
	bool moved = false;
	if (m_orders.size() && m_pNextStation) {
		if (m_orders.front().isItemFilled(this->getItemName())) {
			*m_pNextStation += std::move(m_orders.front());
			m_orders.pop_front();
			moved = true;
		}		
	}

	return moved;
}

void Workstation::setNextStation(Station& station) {
	m_pNextStation = (Workstation*)&station;
}

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	bool completed = false;
	if (m_orders.size() && m_orders.front().isOrderFilled()) {
		order = std::move(m_orders.front());
		m_orders.pop_front();		
		completed = true;
	}

	return completed;
}

void Workstation::display(std::ostream& os) const {
	os << this->getItemName() << " --> ";
	if (m_pNextStation) {
		os << m_pNextStation->getItemName() << std::endl;
	}
	else {
		os << "END OF LINE" << std::endl;
	}
}

Workstation& Workstation::operator+=(CustomerOrder&& customerOrder) {
	//move the para onto the back of queue
	m_orders.push_back(std::move(customerOrder));
	return *this;
}