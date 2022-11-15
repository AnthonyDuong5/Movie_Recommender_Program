#ifndef __MENUCLASS__
#define __MENUCLASS__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>  
#include <stdlib.h> 

#include "json/json.hpp"
#include "movie.hpp"
#include "movieList.hpp"

class Menu {
		void printMenu();
		int getPrompt();	//this gets user's choice from menu
		void processPrompt(const int& prompt);
		void getCriteria();
		void printTenRandomMovies();
};

#endif