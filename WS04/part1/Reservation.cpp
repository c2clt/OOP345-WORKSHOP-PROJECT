//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/*
Student Name: Sirui Xie
Student ID: 103013181
E-mail: sxie17@myseneca.ca
Date: 2020-06-19
*/
#include<iostream>
#include<string>
#include<iomanip>
#include"Reservation.h"

namespace sdds {

	Reservation::Reservation() {
	
		res_id = "";
		res_name = "";
		res_email = "";
		res_people = 0;
		res_day = 0;  
		res_hour = 0; 
	}
	Reservation::Reservation(const std::string& res) {

		size_t poS = 0;
		size_t posOfC = res.find(':');
		this->trim(res_id = res.substr(poS, posOfC - poS));
		
		poS = posOfC + 1;
		posOfC = res.find(',', poS);
		this->trim(res_name = res.substr(poS, posOfC - poS));
		
		poS = posOfC + 1;
		posOfC = res.find(',', poS);
		this->trim(res_email = res.substr(poS, posOfC - poS));
		
		poS = posOfC + 1;
		posOfC = res.find(',', poS);
		res_people = std::stoi(res.substr(poS, posOfC - poS));
		
		poS = posOfC + 1;
		posOfC = res.find(',', poS);
		res_day = std::stoi(res.substr(poS, posOfC - poS));
		
		poS = posOfC + 1;
		posOfC = res.find(',', poS);
		res_hour = std::stoi(res.substr(poS, posOfC - poS));
		

	}

	std::ostream& operator<<(std::ostream& os, const Reservation& res) {

		std::string email = "<" + res.res_email + ">";
		os << "Reservation " << res.res_id << ": " << std::setw(10) << std::right << res.res_name << "  " << std::setw(20) << std::left << email << std::right;
		
		if (6 < res.res_hour && res.res_hour <= 9)
		{
			os << "    Breakfast on day " << res.res_day << " @ " << res.res_hour << ":00 for " << res.res_people << " people." << std::endl;
		}
		else if (11 < res.res_hour && res.res_hour <= 15)
		{
			os << "    Lunch on day " << res.res_day << " @ " << res.res_hour << ":00 for " << res.res_people << " people." << std::endl;
		}
		else if (17 < res.res_hour && res.res_hour <= 21)
		{
			os << "    Dinner on day " << res.res_day << " @ " << res.res_hour << ":00 for " << res.res_people << " people." << std::endl;
		}
		else
		{
			os << "    Drinks on day " << res.res_day << " @ " << res.res_hour << ":00 for " << res.res_people << " people." << std::endl;
		}

		return os;
	}

	void Reservation::trim(std::string& str) const {
		size_t i = 0;
		for (i = 0; i < str.length() && str[i] == ' '; ++i);
		//{
			str = str.substr(i);
		//}
		for (i = str.length() - 1; i > 0 && str[i - 1] == ' '; --i);
		//{
			str = str.substr(0, i);
		//}
	
	}

}

