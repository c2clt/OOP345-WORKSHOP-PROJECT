/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 1: Across Translation Units
// File:  event.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  05/29/2020
// Description: implementation of the Event module
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "event.h"

unsigned int g_sysClock = 0u;
namespace sdds {
	Event::Event() {
		desc = nullptr;
		time = 0u;
	}

	Event::Event(const Event& src) {
        // Shallow copy the static part
		time = src.time;

        // Deep copy dynamic allocated part
        if (src.desc != nullptr) {
		    desc = new char[strlen(src.desc) + 1];
	        strcpy(desc, src.desc);
        } else {
            desc = nullptr;
        }
	}

	Event& Event::operator=(const Event& src) {
		if (this != &src) {
			time = src.time;
			delete[] desc;
			if (src.desc != nullptr) {
				desc = new char[strlen(src.desc) + 1];
				strcpy(desc, src.desc);
			}
			else {
				desc = nullptr;
			}
		}

		return *this;
	}

	void Event::display() const {
		static unsigned int counter = 0u;
		++counter;
		if (desc != nullptr) {
			unsigned int ss = time % 60u;
			unsigned int mm = (time / 60u) % 60u;
			unsigned int hh = ((time / 60u) / 60u) % 24u;
			std::cout.width(3);
			std::cout << counter << ". ";
			std::cout.fill('0');
			std::cout.width(2);
			std::cout << hh << ":";
			std::cout.width(2);
			std::cout << mm << ":";
			std::cout.width(2);
			std::cout << ss;
			std::cout.fill(' ');
			std::cout << " -> " << desc << std::endl;
		}
		else {
			std::cout.width(3);
			std::cout << counter << ". [ No Event ]" << std::endl;
		}
	}

	void Event::setDescription(const char* description) {
		if (description != nullptr && description[0] != '\0') {
		    delete[] desc;
            desc = new char[strlen(description) + 1];
			strcpy(desc, description);
			time = g_sysClock;
		}
		else {
			//delete[] desc;
			*this = Event();
		}
	}
	Event::~Event() {
		delete[] desc;
        desc = nullptr;
	}
}
