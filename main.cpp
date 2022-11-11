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

vector<string> getGenreList(movie&);
int main(){
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    cout << "database has been set" << endl;
    
    //default print movie list below
    //MovieDatabase.printMovies(MovieDatabase.returnList());

    //testing sortYear
    //MovieDatabase.sortYear(MovieDatabase.returnList());

    vector<string> Glist = MovieDatabase.returnList().at(1).return_genreList();
    for (int i = 0 ; i < Glist.size(); i++){
        cout<< Glist.at(i)<< " ";
    }
    cout<<endl;

}

