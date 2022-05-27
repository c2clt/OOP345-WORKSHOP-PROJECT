/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 3: Templates
// File:  PairSummable.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/08/2020
// Description: derived from Pair<K, V>
// representing a Pair with summation and key alignment functionality.
***********************************************************************/

#ifndef SDDS_PAIRSUMMABLE_H__
#define SDDS_PAIRSUMMABLE_H__

#include <iomanip>
#include "Pair.h"

namespace sdds {
	template <typename K, typename V>
	class PairSummable : public Pair<K, V> {
		static V initVal;
		static size_t width;
	public:
		PairSummable() : Pair<K, V>() {

		}

		PairSummable(const K& key, const V& value) : Pair<K, V>(key, value) {
			if (width < key.size()) {
				width = key.size();
			}			
		}

		static const V& getInitVal() {
			return initVal;
		}

		V sum(const K& key, const V& val) const {
			return key == this->key() ? val + this->value() : val;
		}

		void display(std::ostream& os) const {
			os << std::left << std::setw(width);
			Pair<K, V>::display(os);
			os << std::right;
		}
	};

	template <typename K, typename V>
	size_t PairSummable<K, V>::width{0u};

	template <>
	std::string PairSummable<std::string, std::string>::initVal = "";

	template <>
	int PairSummable<std::string, int>::initVal = 0;

	template <>
	std::string PairSummable<std::string, std::string>::sum(const std::string& key, const std::string& val) const {
		std::string res = val;
		if (key == this->key()) {
			res = val == "" ? this->value() : val + ", " + this->value();
		}
		return  res;
	}
}
#endif 