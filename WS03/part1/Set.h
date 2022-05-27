/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 3: Templates
// File:  Set.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/05/2020
// Description: 
// defining a class template for a collection of elements of any data type
***********************************************************************/
#ifndef SDDS_SET_H__
#define SDDS_SET_H__
#include <cassert>

namespace sdds {
	template <class T, size_t N>
	class Set {
		T arr[N]{};
		size_t n{0u};
	public:
		size_t size() const {
			return n;
		}

		const T& operator[](size_t idx) const {
			assert(idx < n && "Index out of range");
			return arr[idx];			
		}

		void operator+=(const T& item) {
			if (n < N) {
				arr[n++] = item;
			}
		}
	};
}
#endif