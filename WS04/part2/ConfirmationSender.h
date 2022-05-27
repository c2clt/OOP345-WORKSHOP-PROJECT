/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 4: Containers
// File:  ConfirmationSender.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/18/2020
// Description: definition of ConfirmationSender Module
***********************************************************************/
#ifndef SDDS_CONFIRMATIONSENDER_H__
#define SDDS_CONFIRMATIONSENDER_H__

#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		const sdds::Reservation** m_res = nullptr;
		size_t m_cnt = 0u;
	public:
		ConfirmationSender() { }
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirmSender);
		~ConfirmationSender();
	};
	
}
#endif