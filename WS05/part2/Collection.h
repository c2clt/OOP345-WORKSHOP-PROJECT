/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 5: Functions and Error Handling
// File:  Collection.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/22/2020
// Description: definition of Template Class Collection
***********************************************************************/
#ifndef SDDS_COLLECTION_H__
#define SDDS_COLLECTION_H__

#include <iostream>
#include <exception>

namespace sdds {
	template <typename T>
	class Collection {
		std::string m_name  = "";
		T* m_items = nullptr;
		size_t m_num = 0u;
		void (*observeItemAdded)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection<T>(const std::string name) {
			m_name = name;
		}

		Collection<T>(const Collection<T>& src) = delete;

		Collection<T>& operator=(const Collection<T>& src) = delete;

		~Collection<T>() {
			delete[] m_items;
			m_items = nullptr;
		}
		const std::string& name() const {
			return m_name;
		}

		size_t size() const {
			return m_num;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			observeItemAdded = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool found = false;
			size_t i = 0u;
			for (i = 0u; i < m_num && (!found); i++) {
				if (m_items[i].title() == item.title()) {
					found = true;
				}
			}

			if (!found) {
				T* tmp = new T[m_num + 1];
				for (i = 0u; i < m_num; i++) {
					tmp[i] = m_items[i];
				}
				tmp[m_num] = item;

				delete[] m_items;
				m_items = tmp;
				m_num++;

				if (observeItemAdded != nullptr) {
					observeItemAdded(*this, m_items[m_num - 1]);
				}
			}

			

			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= m_num) {
				std::string errMsg = "Bad index ["
					+ std::to_string(idx)
					+ "]. Collection has ["
					+ std::to_string(m_num)
					+ "] items.";
				throw std::out_of_range(errMsg);
			}

			return m_items[idx];
		}

		T* operator[](std::string title) const {
			T* address = nullptr;
			for (size_t i = 0u; i < m_num; i++) {
				if (m_items[i].title() == title) {
					address = &m_items[i];
				}
			}

			return address;
		}
	};

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& c) {
		for (size_t i = 0u; i < c.size(); i++) {
			os << c[i];
		}

		return os;
	}
}
#endif