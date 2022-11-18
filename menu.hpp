#ifndef __MENUCLASS__
#define __MENUCLASS__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <stdio.h>  
#include <stdlib.h> 
#include "user.hpp"

class Menu {
	private:
        User user;
	public:
		Menu();
		void printMenu();
		int getPrompt();	//this gets user's choice from menu
		void processPrompt(const int& prompt);
		void printTenRandomMovies();
		void advancedMovieFilter();
		
		void getCriteria(string, double, double, int, int, int);
		bool promptYesOrNo(string);

		int optionTracker = 0;
};

#endif