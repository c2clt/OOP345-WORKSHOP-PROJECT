/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 2: Move and Copy Semantics
// File:  TimedEvent.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/02/2020
// Description: definition of the TimedEvent module
***********************************************************************/

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds {
	const int MAX_RECORDS = 7;
	class TimedEvents {
		int nr {0};
		std::chrono::steady_clock::time_point ts;
		std::chrono::steady_clock::time_point te;
		struct {
			std::string msg{};
			std::string units{};
			std::chrono::steady_clock::duration duration{};
		} events[MAX_RECORDS];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* msg);
		friend std::ostream& operator<<(std::ostream& out, const TimedEvents& events);
		virtual ~TimedEvents();
	};
}
#endif
