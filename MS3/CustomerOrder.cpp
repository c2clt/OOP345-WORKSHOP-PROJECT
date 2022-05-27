/***********************************************************************
// Name: Jingmin (Jessica) Zhou
// Seneca Student ID: 119766194
// Seneca email: jzhou175@myseneca.ca
// Date of completion: July 16th 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// OOP345 Project: Milestone 3
// File:  CustomerOrder.cpp
// Description: implementation of CustomerOrder Module
***********************************************************************/
#include <vector>
#include <iomanip>
#include <memory>
#include "CustomerOrder.h"
#include "Utilities.h"

size_t CustomerOrder::m_widthField = 0u;

CustomerOrder::CustomerOrder(const std::string& record) {
	Utilities util;
	size_t next_pos = 0u;
	bool more = false;	

	if (!record.empty()) {
		m_name = util.extractToken(record, next_pos, more);
		m_product = util.extractToken(record, next_pos, more);

		std::vector<Item*> items;
		while (more) {
			items.push_back(new Item(util.extractToken(record, next_pos, more)));
		}

		m_cntItem = items.size();
		m_lstItem = new Item* [m_cntItem];
		for (size_t i = 0u; i < m_cntItem; i++) {
			m_lstItem[i] = std::move(items[i]);
		}

		m_widthField = m_widthField > util.getFieldWidth() ? m_widthField : util.getFieldWidth();
	}
}

CustomerOrder::CustomerOrder(const CustomerOrder& src) {
	throw "Copy constructor should not be called";
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
	*this = std::move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
	if (this != &src) {
		m_name = src.m_name;
		m_product = src.m_product;

		for (size_t i = 0u; i < m_cntItem; i++) {
			delete m_lstItem[i];
			m_lstItem[i] = nullptr;
		}
		delete[] m_lstItem;
		m_lstItem = nullptr;

		m_cntItem = src.m_cntItem;
		m_lstItem = src.m_lstItem;

		src.m_name = "";
		src.m_product = "";
		src.m_cntItem = 0u;
		src.m_lstItem = nullptr;
	}

	return *this;
}

CustomerOrder::~CustomerOrder() {
	for (size_t i = 0u; i < m_cntItem; i++) {
		delete m_lstItem[i];
		m_lstItem[i] = nullptr;
	}

	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::isOrderFilled() const {
	bool allFilled = true;
	for (size_t i = 0u; i < m_cntItem && allFilled; i++) {
		if (!m_lstItem[i]->m_isFilled) {
			allFilled = false;
		}
	}

	return allFilled;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	bool res = true, found = false;
	for (size_t i = 0u; i < m_cntItem && !found; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {
			res = m_lstItem[i]->m_isFilled;
			found = true;
		}
	}

	return res;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	for (size_t i = 0u; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == station.getItemName()) {
			if (station.getQuantity() > 0) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				// Filled: NAME, PRODUCT [ITEM_NAME]
				os << "    Filled ";
			}
			else {
				// Unable to fill: NAME, PRODUCT [ITEM_NAME]
				os << "Unable to fill ";
			}
			os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0u; i < m_cntItem; i++) {
		os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << std::setfill(' ') << "] ";
		os << std::left << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
		if (m_lstItem[i]->m_isFilled) {
			os << "FILLED" << std::endl;
		}
		else {
			os << "MISSING" << std::endl;
		}
	}	
}
