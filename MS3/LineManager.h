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
// File:  LineManager.h
// Description: definition of LineManager Module
***********************************************************************/

#ifndef SDDS_LINEMANAGER_H__
#define SDDS_LINEMANAGER_H__

#include <vector>
#include <deque>
#include "Workstation.h"

class LineManager {
    std::vector<Workstation*> AssemblyLine; // A container containing all the references of the Workstation objects on the assembly line
    std::deque<CustomerOrder> ToBeFilled; // A queue of customer orders to be filled
    std::deque<CustomerOrder> Completed; // A queue of customer orders completed
    unsigned int m_cntCustomerOrder = 0u; // The number of CustomerOrder objects the assembly line started with.

    Workstation* m_firstStation = nullptr;
    Workstation* m_lastStation = nullptr;
public:
    LineManager(const std::string& filename, std::vector<Workstation*>& stations, std::vector<CustomerOrder>& orders);
    bool run(std::ostream& os);
    void displayCompletedOrders(std::ostream& os) const;
    void displayStations() const;
    void displayStationsSorted() const;
};
#endif
