/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 3: Templates
// File:  Pair.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/08/2020
// Description: defining a class tempalte for managing a Key-Value pair
***********************************************************************/
#ifndef SDDS_PAIR_H__
#define SDDS_PAIR_H__

namespace sdds {
	template <typename K, typename V>
	class Pair {
		K m_key;
		V m_value;
	public:
		Pair() : m_key{ }, m_value{ } {
		}

		Pair(const K& key, const V& value) {
			m_key = key;
			m_value = value;
		}

		const K& key() const {
			return m_key;
		}

		const V& value() const {
			return m_value;
		}

		virtual void display(std::ostream& os) const {
			os << m_key << " : " << m_value << std::endl;
		}
	};

	template <typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}
}
#endif