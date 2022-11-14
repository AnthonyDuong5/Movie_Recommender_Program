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

	public:
		User();
		vector <movie>& getFavoritesList(){ return Favorites;}
		void printMenu();
		void AddToFavorite(const movie& m1);
		void getCriteria();
		void printTenRandomMovies();
};





#endif