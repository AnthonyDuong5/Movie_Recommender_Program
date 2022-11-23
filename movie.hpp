#ifndef __MOVIE_H__
#define  __MOVIE_H__

#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;
//declare enum  
enum Genre{
	Adventure=1,
    Action=2,
    Animation=3,
    Children=4,
    Comedy=5,
    Crime=6,
    Documentary=7,
    Drama=8,
    Fantasy=9,
    FilmNoir=10,
    Horror=11,
    IMAX=12,
    Musical=13,
    Mystery=14,
    Romance=15,
    SciFi=16,
    Thriller=17,
    War=18,
    Western=19
};
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
        vector<Genre> genre_list;
        movie(string title, string director, string cast, double rating, int imdbId, int itemId, int year, vector<string> genreList);
        string getTitle() const;
        int getYear() const;
        string getDirector() const;
        string getCast() const;
        double getRating() const;
        int getImdbId() const;
        int getItemId() const;
        vector<string> getGenreList() const;
        void printMovie();
        void printMovie_2();
        
        
};



#endif
