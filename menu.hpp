#ifndef __MENUCLASS__
#define __MENUCLASS__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
		void getCriteria();
		void printTenRandomMovies();
		void addToFavorites();
		void searchForMovie();
		void quit();
		void repeat() {
			printMenu();
			processPrompt(getPrompt());
		}

		int optionTracker = 0;
		vector<movie> PrintedList;
};

#endif