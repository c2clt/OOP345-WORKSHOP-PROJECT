/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 7: STL Algorithms
// File:  SongCollection.cpp
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  07/11/2020
// Description: implementation of SongCollection Module
***********************************************************************/
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "SongCollection.h"

namespace sdds {
    void SongCollection::trim(std::string& str) const {
        if (!str.empty())
        {
            str.erase(0, str.find_first_not_of(" "));
            str.erase(str.find_last_not_of(" ") + 1);
        }
    }

    SongCollection::SongCollection(const char* filename) {
        std::ifstream file(filename);
        if (!file) {
            std::string str(filename);
            std::string errmsg = "ERROR: Cannot open file[";
            errmsg += str;
            errmsg += "].";
            throw errmsg;
        }

        while (!file.eof()) {
            Song temp;
            std::string song;
            getline(file, song);

            size_t pos = 0u;
            trim(temp.title = song.substr(pos, 25));

            pos += 25;
            trim(temp.artist = song.substr(pos, 25));

            pos += 25;
            trim(temp.album = song.substr(pos, 25));

            pos += 25;
            std::string tempYear = "";
            trim(tempYear = song.substr(pos, 5));
            if (!tempYear.empty()) {
                temp.year = stoi(tempYear);
            }            

            pos += 5;
            temp.length = stoi(song.substr(pos, 5));

            pos += 5;
            temp.price = stod(song.substr(pos, 5));

            songs.push_back(temp);
        }
    }

    void SongCollection::display(std::ostream& out) const {
        std::for_each(songs.begin(), songs.end(), [&out](const Song s) { out << s << std::endl; });
    }

    std::ostream& operator<<(std::ostream& out, const Song& theSong) {
        out << "| " << std::left << std::setw(20) << theSong.title;
        out << " | " << std::left << std::setw(15) << theSong.artist;
        out << " | " << std::left << std::setw(20) << theSong.album;
        out << " | " << std::right << std::setw(6);
        if (theSong.year) {
            out << theSong.year;
        }
        else {
            out << "";
        }        
        size_t ss = theSong.length % 60;
        size_t mm = theSong.length / 60;
        out << " | " << std::to_string(mm) << ":" << std::setfill('0') << std::setw(2) << std::to_string(ss) << std::setfill(' ');
        out << " | " << std::fixed << std::setprecision(2) << theSong.price << " |";

        return out;
    }
}
