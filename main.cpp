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


int main(){
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    cout << "database has been set" << endl;

    //default print movie list below
    //MovieDatabase.printMovies(MovieDatabase.returnList());

    //testing sortYear
    MovieDatabase.sortYear(MovieDatabase.returnList());
}

