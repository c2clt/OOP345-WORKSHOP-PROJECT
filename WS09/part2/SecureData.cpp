/******************************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
*******************************************************************************
// OOP345 Workshop 9 - Multi-Threading
// File:  SecureData.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  07/27/2020
// Description: inplementation of SecureData Module
********************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
		//converter(text, key, nbytes, Cryptor());
		int nTask = nbytes / 3;
		std::thread t[3];

		for (size_t i = 0u; i < 3; i++) {
			auto p = std::bind(converter, &text[i * nTask], key, nTask, Cryptor());
			t[i] = std::thread(p);
		}
		for (size_t i = 0u; i < 3; i++) {
			t[i].join();
		}
		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			std::ofstream ofile(file, std::ios::out|std::ios::binary|std::ios::trunc);

			// TODO: write data into the binary file
			//         and close the file
			ofile.write(text, nbytes);
			ofile.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		std::ifstream infile(file, std::ios::in|std::ifstream::binary);

		// TODO: - allocate memory here for the file content
		infile.seekg(0, std::ios::end);
		int n = (int)infile.tellg() + 1;
		char* p = new char[n];
		// TODO: - read the content of the binary file
		while (infile) {
			infile.read(p++, 1);
		}
		*--p = '\0';

		delete[] p;

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
