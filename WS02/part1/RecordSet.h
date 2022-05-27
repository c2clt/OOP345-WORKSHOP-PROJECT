/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 2: Move and Copy Semantics
// File:  RecordSet.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/02/2020
// Description: definition of the RecordSet module
***********************************************************************/

#ifndef SDDS_RECORDSET_H__
#define SDDS_RECORDSET_H__

#include <iostream>

namespace sdds {
	class RecordSet {
		std::string* S {nullptr};
		size_t numOfStr {0};
	public:
		RecordSet();
		RecordSet(const char* fn);
		RecordSet(const RecordSet& src);
		RecordSet& operator=(const RecordSet& src);
		size_t size();
		std::string getRecord(size_t index);
		virtual ~RecordSet();
	};
}
#endif
