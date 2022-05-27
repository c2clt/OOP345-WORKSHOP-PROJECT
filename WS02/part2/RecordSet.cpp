/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 2: Move and Copy Semantics
// File:  RecordSet.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/02/2020
// Description: implementation of the RecordSet module
***********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "RecordSet.h"

namespace sdds {
	RecordSet::RecordSet() : S{nullptr}, numOfStr{0u} { }

	RecordSet::RecordSet(const char* fn) {
		std::ifstream fi(fn);

		while (!fi.eof()) {
			if (fi.get() == ' ') {
				numOfStr++;
			}			
		}
		numOfStr++;

		fi.clear();
		fi.seekg(std::ios::beg);
		
		S = new std::string[numOfStr];
		for (size_t i = 0; i < numOfStr; i++) {
			std::getline(fi, S[i], ' ');
		}		
	}

	RecordSet::RecordSet(const RecordSet& src) {
		if (src.S != nullptr) {
			numOfStr = src.numOfStr;
			S = new std::string[numOfStr];
			for (size_t i = 0; i < numOfStr; i++) {
				S[i] = src.S[i];
			}
		}
		else {
			*this = RecordSet();
		}
	}

	RecordSet& RecordSet::operator=(const RecordSet& src) {
		if (this != &src) {
			numOfStr = src.numOfStr;
			delete[] S;
			if (src.S != nullptr) {
				S = new std::string[numOfStr];
				for (size_t i = 0; i < numOfStr; i++) {
					S[i] = src.S[i];
				}
			}
			else {
				*this = RecordSet();
			}
		}
		return *this;
	}

	RecordSet::RecordSet(RecordSet&& src) {
		*this = std::move(src);
	}

	RecordSet& RecordSet::operator=(RecordSet&& src) {
		if (this != &src) {
			delete[] S;
			S = src.S;
			numOfStr = src.numOfStr;			
			src.S = nullptr;
			src.numOfStr = 0u;
		}
		return *this;
	}

	size_t RecordSet::size() {
		return numOfStr;
	}

	std::string RecordSet::getRecord(size_t index) { 
		return index < numOfStr ? S[index] : "";
	}

	RecordSet::~RecordSet() {
		delete[] S;
		S = nullptr;
	}
}