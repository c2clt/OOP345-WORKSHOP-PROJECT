/******************************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
*******************************************************************************
// OOP345 Workshop 8: Smart Poniter
// File:  Utilities.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  07/21/2020
// Description: inplementation of Utilities Module
********************************************************************************/

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0u; i < desc.size(); i++) {
			for (size_t j = 0u; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* p = new Product(desc[i].desc, price[j].price);
					try {
						p->validate();
					}
					catch(...) {
						delete p;
						throw;
					}
					priceList += p;
					delete p;
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0u; i < desc.size(); i++) {
			for (size_t j = 0u; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> p(new Product(desc[i].desc, price[j].price));
					p->validate();
					priceList += p;
				}
			}
		}

		return priceList;
	}
}