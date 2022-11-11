#ifndef __MOVIE_H__
#define  __MOVIE_H__

#include <iostream>
#include <string>
#include <list>
#include <vector>
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
        vector<string> genreList;

    public: 
        
        movie(string title, string director, string cast, double rating, int imdbId, int itemId, int year, vector<string> genreList);
        string getTitle() const;
        int getYear() const;
        string getDirector() const;
        string getCast() const;
        double getRating() const;
        int getImdbId() const;
        int getItemId() const;
        vector<string> getGenreList() const;

        
};



#endif
