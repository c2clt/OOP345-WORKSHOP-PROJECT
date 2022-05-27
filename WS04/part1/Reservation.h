//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/*
Student Name: Sirui Xie
Student ID: 103013181
E-mail: sxie17@myseneca.ca
Date: 2020-06-19
*/
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include<iostream>
#include<cstring>
#include<iomanip>

namespace sdds {
	
		
	class Reservation
	{
	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);

		void trim(std::string& str) const;
	private:
		std::string res_id;
		std::string res_name;
		std::string res_email;
		size_t res_people = 0;
		size_t res_day;  //1-31
		size_t res_hour; // 1-24
	};
	
}

#endif // !SDDS_RESERVATION_H
