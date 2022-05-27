#pragma once
/***********************************************************************
// Name: Jingmin (Jessica) Zhou
// Seneca Student ID: 119766194
// Seneca email: jzhou175@myseneca.ca
// Date of completion: July 16th 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// OOP345 Project: Milestone 2
// File:  CustomerOrder.h
// Description: definition of CustomerOrder Module
***********************************************************************/
#ifndef SDDS_CUSTOMERORDER_H__
#define SDDS_CUSTOMERORDER_H__

#include <iostream>
#include "Station.h"

struct Item
{
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_isFilled = false;

    Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder {

    std::string m_name = ""; 
    std::string m_product = ""; 
    unsigned int m_cntItem = 0u; 
    Item** m_lstItem = { nullptr }; // – a dynamically allocated array of pointers.

    static size_t m_widthField; 
public:
    CustomerOrder() {};
    CustomerOrder(const std::string& record);
    CustomerOrder(const CustomerOrder& src); // throw excepetion if called
    CustomerOrder& operator=(const CustomerOrder& src) = delete;
    CustomerOrder(CustomerOrder&& src) noexcept; 
    CustomerOrder& operator=(CustomerOrder&& src) noexcept;
    ~CustomerOrder();
    bool isOrderFilled() const;
    bool isItemFilled(const std::string& itemName) const;
    void fillItem(Station& station, std::ostream& os);
    void display(std::ostream& os) const;
};

#endif