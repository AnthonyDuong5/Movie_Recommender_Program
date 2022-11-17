#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <stdio.h>  
#include <stdlib.h> 
#include <map>

#include "user.hpp"



User::User(){
	movieList MovieDatabase;
	MovieDatabase.readMovieListFiles();
	ViewingList = DefaultList = MovieDatabase.returnList();
	UserName = "user1";		//we could ask the username later, doesn't matter much.
}

void User::removeFromViewingList(unsigned idx) {
	ViewingList.erase(ViewingList.begin() + idx);
}



vector<movie> User::getRec(){
	vector<movie> rec;

	//step 1: find year/director/gennres frequency from Favorites
	vector<int> yearlist;
	vector<string>director;
	vector<Genre> genres;
	for(auto x: Favorites){
        yearlist.push_back(x.getYear());
		director.push_back(x.getDirector());
		for(auto y: x.genre_list){
			genres.push_back(y);
		}
    }
	map<int, int> freqMap = help_getFreq(yearlist);	
	int MostSeenYear = help_getMaximumValue(freqMap).first;

	map<string, int> freqMap2 = help_getFreq(director);	
	string MostSeenDirector = help_getMaximumValue(freqMap2).first;

	map<Genre, int> freqMap3 = help_getFreq(genres);	
	Genre MostSeenGenres = help_getMaximumValue(freqMap3).first;


	//step 4: use these criteria (year, director, director) to generate a rec list.
	//may be using different combination of criteria based on the condition of Favorites list
	//open to discussion.. . 



	return rec;

}

