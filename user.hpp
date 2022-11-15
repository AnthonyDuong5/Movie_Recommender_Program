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
		vector<movie> ViewingList;
		int prompt = 0;

		//adding a movieList,can use funcions from the movieList
		movieList userFavList;

	public:
		User();

		void AddToFavorite(const movie& m1);
		vector <movie>& getFavoritesList(){ return Favorites;}
		vector<movie> getDefaultList(){return DefaultList;}
		vector<movie> getViewingList(){return ViewingList;}
		void removeFromViewingList(unsigned idx);

		//this function will use something from  movieList userFavList
		vector<movie> getRec();

		//void printMenu();
		//int getPrompt();	//this gets user's choice from menu
		//void processPrompt(const int& prompt);
		//void getCriteria();
		//void printTenRandomMovies();
		

};





#endif