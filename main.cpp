#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>  
#include <stdlib.h> 

#include "json/json.hpp"
#include "movie.hpp"
#include "movieList.hpp"

using namespace std;
using json = nlohmann::json;

// void printMovie(const movie&);
// void getYear(movie&);

int main(){
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    cout << "database has been set" << endl;
    MovieDatabase.printMovies(MovieDatabase.returnList());
}
