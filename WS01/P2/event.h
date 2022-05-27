/***********************************************************************
// Sources: 
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 1: Across Translation Units 
// File:  event.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  05/29/2020
// Description: definition of the Event module
***********************************************************************/

#ifndef SDDS_EVENT_H__
#define SDDS_EVENT_H__
 
extern unsigned int g_sysClock;
//const int MAXDESC = 127;

namespace sdds {
	class Event {
	private:
		char* desc;
		unsigned int time;
	public:
		Event();
	    Event(const Event& src);
		Event& operator=(const Event& src);
		void display() const;
		void setDescription(const char* description);
		virtual ~Event();
	};
}

#endif // !SDDS_EVENT_H__
