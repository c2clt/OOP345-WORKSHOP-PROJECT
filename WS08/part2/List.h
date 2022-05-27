/******************************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
*******************************************************************************
// OOP345 Workshop 8: Smart Poniter
// File:  List.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  07/21/2020
// Description: List Template Module
********************************************************************************/

#ifndef SDDS_LIST_H
#define SDDS_LIST_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
    template <typename T>
    class List {
		std::vector<T> list;
	public:
		List() { }
		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
            while (file) {
                T e;
                if (e.load(file))
                    list.push_back(T(e));
            }
		}
		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		// TODO: Overload the += operator with a smart pointer
		//       as a second operand.
		void operator+=(std::unique_ptr<T>& tPtr) {
			list.push_back(*tPtr);
		}

		// TODO: Overload the += operator with a raw pointer
		//       as a second operand.
		void operator+=(const T* tPtr) {
			list.push_back(*tPtr);
		}

		void display(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.display(os);
        }
	};

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}
#endif