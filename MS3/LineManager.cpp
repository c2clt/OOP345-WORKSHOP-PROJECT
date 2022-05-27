/***********************************************************************
// Name: Jingmin (Jessica) Zhou
// Seneca Student ID: 119766194
// Seneca email: jzhou175@myseneca.ca
// Date of completion: July 20th 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// OOP345 Project: Milestone 3
// File:  LineManager.cpp
// Description: implementation of LineManager Module
***********************************************************************/
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cassert>
#include "LineManager.h"
#include "Utilities.h"

LineManager::LineManager(const std::string& filename, std::vector<Workstation*>& stations, std::vector<CustomerOrder>& orders) {
	std::ifstream file(filename);
	if (!file) {
		throw std::string("Unable to open [") + filename + "] file.";
	}

	Utilities util;
	std::string record = "";
	std::string currStation = "";
	std::string nextStation = "";
	size_t next_pos;
	bool more;

	while (!file.eof()) {		
		next_pos = 0u;
		std::getline(file, record);
		
		currStation = util.extractToken(record, next_pos, more);
		if (more) {
			nextStation = util.extractToken(record, next_pos, more);
		}
		else {
			nextStation = "";
		}

		for (size_t i = 0u; i < stations.size(); i++) {
			if (stations[i]->getItemName() == currStation) {
				for (size_t j = 0u; j < stations.size(); j++) {
					if (stations[j]->getItemName() == nextStation) {
						stations[i]->setNextStation(*stations[j]);
						break;
					}
				}
				if (m_firstStation == nullptr) {
					m_firstStation = stations[i];
				}
				m_lastStation = stations[i];
			}
		}

	}

	for (size_t i = 0u; i < orders.size(); i++) {
		ToBeFilled.push_back(std::move(orders[i]));
	}
	m_cntCustomerOrder = ToBeFilled.size();

	AssemblyLine = stations;
}

bool LineManager::run(std::ostream& os) {
	bool allFilled = true;
	static size_t counter = 0u;
	counter++;

	os << "Line Manager Iteration: " << counter << std::endl;

	if (!ToBeFilled.empty()) {
		*m_firstStation += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (size_t i = 0u; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->runProcess(os);
	}

	for (size_t i = 0u; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->moveOrder();
	}

	CustomerOrder order;
	if (m_lastStation->getIfCompleted(order)) {
		Completed.push_back(std::move(order));
	}

	if (m_cntCustomerOrder > Completed.size()) {
		allFilled = false;
	}
	
	return allFilled;
}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (size_t i = 0u; i < Completed.size(); i++) {
		Completed[i].display(os);
	}
}

void LineManager::displayStations() const {
	for (size_t i = 0u; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->display(std::cout);
	}
}

void LineManager::displayStationsSorted() const {
	const Workstation* p = m_firstStation;
	while (p != nullptr) {
		p->display(std::cout);
		p = p->getNextStation();
	}
}