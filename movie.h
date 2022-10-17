#ifndef __MOVIE_H__
#define  __MOVIE_H__

#include <iostream>
#include <string>
#include <list>
using namespace std;

class movie{

public:
    string title;
    int year;
    string director;
    string cast;
    double rating;
    int imbdId;
    int itemId;
    movie(string title, string director, string cast, double rating, int imbdId, int itemId);
};


#endif