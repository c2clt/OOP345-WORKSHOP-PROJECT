#pragma once
/***********************************************************************
// Sources:
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
***********************************************************************
// OOP345 Workshop 7: STL Algorithms
// File:  SongCollection.h
// Name:  Jingmin (Jessica) Zhou
// Email: jzhou175@myseneca.ca
// ID:    119766194
// Date:  07/11/2020
// Description: definition of SongCollection Module
***********************************************************************/

#ifndef SDDS_SONGCOLLECTION_H__
#define SDDS_SONGCOLLECTION_H__

#include <iostream>
#include <vector>
#include <list>
namespace sdds {
	struct Song {
        std::string m_artist = "";
        std::string m_title = "";
        std::string m_album = "";
        double m_price = 0.0f;
        size_t m_year = 0u;
        size_t m_length = 0u;
	};

	class SongCollection {
        std::vector<Song> songs;

        void trim(std::string& str) const;
    public:
        SongCollection(const char* filename);
        void display(std::ostream& out) const;
        void sort(const std::string& str);
        void cleanAlbum();
        bool inCollection(const std::string name) const;
        std::list<Song> getSongsForArtist(const std::string name) const;
	};
    std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif
