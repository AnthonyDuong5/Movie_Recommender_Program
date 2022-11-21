#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>  
#include <stdlib.h> 

#include "json/json.hpp"
#include "movie.hpp"
#include "movieList.hpp"
#include "user.hpp"
#include "menu.hpp"

using namespace std;
using json = nlohmann::json;

// vector<string> getGenreList(movie&);
int main(){

    srand(time(0));
    // movieList MovieDatabase;
    // MovieDatabase.readMovieListFiles();
    // cout << "database has been set" << endl;

    
    //default print movie list below
    //MovieDatabase.printMovies(MovieDatabase.returnList());

    //testing sortYear
    //MovieDatabase.sortYear(MovieDatabase.returnList());
    //User user1;
    // user1.printMenu();
    // int choice = user1.getPrompt();
    // user1.processPrompt(choice);
    Menu defMenu;
    return 0;


}

