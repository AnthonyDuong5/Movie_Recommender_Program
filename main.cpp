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

    Menu defMenu;

    defMenu.runMenu();
    return 0;


}

