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
#include <numeric>
#include <functional>
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
            trim(temp.m_title = song.substr(pos, 25));

            pos += 25;
            trim(temp.m_artist = song.substr(pos, 25));

            pos += 25;
            trim(temp.m_album = song.substr(pos, 25));

            pos += 25;
            std::string tempYear = "";
            trim(tempYear = song.substr(pos, 5));
            if (!tempYear.empty()) {
                temp.m_year = stoi(tempYear);
            }            

            pos += 5;
            temp.m_length = stoi(song.substr(pos, 5));

            pos += 5;
            temp.m_price = stod(song.substr(pos, 5));

            songs.push_back(temp);
        }
    }

    void SongCollection::display(std::ostream& out) const {
        std::for_each(songs.begin(), songs.end(), [&out](const Song s) { out << s << std::endl; });

        out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
        
        size_t totalTime = std::accumulate(songs.begin(), songs.end(), (size_t)0u, [](size_t init, Song s) { return init + s.m_length; });

        size_t ss = totalTime % 60;
        size_t mm = (totalTime / 60) % 60;
        size_t hh = totalTime / 60 / 60;
        out << "|                                                        Total Listening Time: ";
        out << std::to_string(hh) << ":" << std::setfill('0') << std::setw(2) << std::to_string(mm) << ":" << std::setw(2) << std::to_string(ss) << std::setfill(' ') << " |" << std::endl;
    }

    std::ostream& operator<<(std::ostream& out, const Song& theSong) {
        out << "| " << std::left << std::setw(20) << theSong.m_title;
        out << " | " << std::left << std::setw(15) << theSong.m_artist;
        out << " | " << std::left << std::setw(20) << theSong.m_album;
        out << " | " << std::right << std::setw(6);
        if (theSong.m_year) {
            out << theSong.m_year;
        }
        else {
            out << "";
        }        
        size_t ss = theSong.m_length % 60;
        size_t mm = theSong.m_length / 60;
        out << " | " << std::to_string(mm) << ":" << std::setfill('0') << std::setw(2) << std::to_string(ss) << std::setfill(' ');
        out << " | " << std::fixed << std::setprecision(2) << theSong.m_price << " |";

        return out;
    }

    void SongCollection::sort(const std::string& str) {
        auto compare = [str](const Song s1, const Song s2) {
            bool res = false;
            if (str == "length") {
                res = s1.m_length < s2.m_length;
            }
            else if (str == "title") {
                res = strcmp(s1.m_title.c_str(), s2.m_title.c_str()) < 0;
            }
            else if (str == "album") {
                res = strcmp(s1.m_album.c_str(), s2.m_album.c_str()) < 0;
            }
            else {
                const std::string errmsg = str + ": invalid field name for sorting!";
                throw errmsg;
            }

            return res;         
        };

        try {
            std::sort(songs.begin(), songs.end(), compare);
        }
        catch (const std::string errmsg) {
            std::cout << errmsg << std::endl;
            exit(1);
        }        
    }

   void SongCollection::cleanAlbum() {
       auto emptyAlbum = [](Song& s) {
           if (s.m_album == "[None]") {
               s.m_album = "";
           }
       };
       std::for_each(songs.begin(), songs.end(), emptyAlbum);
   }

   bool SongCollection::inCollection(const std::string name) const {
       return std::any_of(songs.begin(), songs.end(), [name](const Song s) { return s.m_artist == name; });
   }

   std::list<Song> SongCollection::getSongsForArtist(const std::string name) const {
        std::list<Song> temp;
        auto addSong = [name, &temp](const Song s) {
            if (s.m_artist == name) {
                temp.push_back(s);
            }
        };
        std::for_each(songs.begin(), songs.end(), addSong);
        return temp;
   }
}
