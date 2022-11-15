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

using namespace std;

User::User(){
	movieList MovieDatabase;
	MovieDatabase.readMovieListFiles();
	DefaultList = MovieDatabase.returnList();
	UserName = "user1";		//we could ask the username later, doesn't matter much.
    //printMenu();
    //int choice = getPrompt();
    //processPrompt(choice);
}


