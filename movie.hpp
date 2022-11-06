#ifndef __MOVIE_H__
#define  __MOVIE_H__

#include <iostream>
#include <string>
#include <list>
using namespace std;

class movie{

    private:
        string title;
        int year;
        string director;
        string cast;
        double rating;
        int imdbId;
        int itemId;
        string Genre;
    public: 
        movie(string title, string director, string cast, double rating, int imdbId, int itemId, int year, string Genre);
        string getTitle() const;
        int getYear() const;
        string getDirector() const;
        string getCast() const;
        double getRating() const;
        int getImdbId() const;
        int getItemId() const;
        string getGenre() const;
        // void setYear(int movieyear);
    };
        




#endif