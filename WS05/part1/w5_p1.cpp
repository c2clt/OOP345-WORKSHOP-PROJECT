/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 5: Functions and Error Handling
// File:  w5_p1.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  06/22/2020
// Description: Testing the Book Module
***********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Book.h"
#include "Book.h"

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	{
		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
		std::ifstream file(argv[1]);
		if (!file) {
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}

		std::string tmpStr;
		size_t i = 0u;

		do {
			std::getline(file, tmpStr);

			if (file) {
				if (tmpStr[0] != '#') {
					library[i] = Book(tmpStr);
					i++;
				}
			}
		} while (i < 7 && file);

		file.close();
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n\n";

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto updatePrice = [&](Book& b) {
		if (b.country() == "US") {
			b.price() *= usdToCadRate;
		}
		if (b.country() == "UK" && b.year() >= 1990 && b.year() <= 1999) {
			b.price() *= gbpToCadRate;
		}
	};
	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (auto& book : library) {
		updatePrice(book);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n";

	return 0;
}
