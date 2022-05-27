/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 4: Containers
// File:  ConfirmationSender.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/18/2020
// Description: implementation of ConfirmationSender Module
***********************************************************************/

#include <iostream>
#include "ConfirmationSender.h"

namespace sdds {
	
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
		if (src.m_res != nullptr) {
			m_cnt = src.m_cnt;
			m_res = new const sdds::Reservation * [m_cnt];
			for (size_t i = 0; i < m_cnt; i++) {
				m_res[i] = src.m_res[i];
			}
		}
		else {
			m_cnt = 0;
			m_res = nullptr;
		}
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) {
		if (src.m_res != nullptr) {
			m_cnt = src.m_cnt;
			m_res = src.m_res;
			src.m_cnt = 0;
			src.m_res = nullptr;
		}
		else {
			m_cnt = 0;
			m_res = nullptr;
		}
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool flag = true;
		for (size_t i = 0; i < m_cnt && flag; i++) {
			if (&res == m_res[i]) {
				flag = false;
			}
		}
		if (flag) {
			const sdds::Reservation** temp = new const sdds::Reservation * [m_cnt];
			for (size_t i = 0; i < m_cnt; i++) {
				temp[i] = m_res[i];
			}
			
			delete[] m_res;
			m_res = new const sdds::Reservation * [m_cnt + 1];
			for (size_t i = 0; i < m_cnt; i++) {
				m_res[i] = temp[i];
			}
			m_res[m_cnt] = &res;
			m_cnt++;

			delete[] temp;
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool flag = true;
		for (size_t i = 0; i < m_cnt && flag; i++) {
			if (&res == m_res[i]) {
				//delete m_res[i];
				m_res[i] = nullptr;
				flag = false;
			}
		}

		if (!flag) {
			const sdds::Reservation** temp = new const sdds::Reservation * [m_cnt - 1];
			for (size_t i = 0u, j = 0u; i < m_cnt && j < m_cnt - 1; i++) {
				if (m_res[i] != nullptr) {
					temp[j] = m_res[i];
					j++;
				}				
			}
			m_cnt--;
			delete[] m_res;
			m_res = new const sdds::Reservation * [m_cnt];
			for (size_t i = 0; i < m_cnt; i++) {
				m_res[i] = temp[i];
			}

			delete[] temp;
		}

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirmSender) {
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (confirmSender.m_res == nullptr) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < confirmSender.m_cnt; i++) {
				os << *(confirmSender.m_res[i]);
			}
		}
		os << "--------------------------" << std::endl;

		return os;
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] m_res;
		m_res = nullptr;
	}
}