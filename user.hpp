#ifndef __USERCLASS__
#define __USERCLASS__

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

class User {
	private:
		string UserName;
		vector<movie> Favorites;
		vector<movie> DefaultList;
		int prompt = 0;

	public:
		User();
		vector <movie>& getFavoritesList(){ return Favorites;}
		void printMenu();
		int getPrompt();	//this gets user's choice from menu
		void processPrompt(const int& prompt);
		void AddToFavorite(const movie& m1);
		void getCriteria();
		void printTenRandomMovies();
};





#endif