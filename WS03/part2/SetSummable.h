/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 3: Templates
// File:  SetSummable.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/08/2020
// Description: derived from Set<T, N>
// managing a collection of summable elements in Set<T, N>
***********************************************************************/
#ifndef SDDS_SETSUMMABLE_H__
#define SDDS_SETSUMMABLE_H__

#include "Set.h"
namespace sdds {
	template <typename T, size_t N, typename K, typename V>
	class SetSummable : public Set<T, N> {
	public:
		V accumulate(const K& key) const {
			auto sumVal = T::getInitVal();
			for (size_t i = 0; i < this->size(); i++) {
				sumVal = (*this)[i].sum(key, sumVal);
			}

			return sumVal;
		}
	};
}
#endif 