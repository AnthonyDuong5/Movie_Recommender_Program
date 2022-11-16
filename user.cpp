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

	//step 1: find year frequency from from Favorites
	vector<int> yearlist;
	for(auto x: Favorites){
        yearlist.push_back(x.getYear());
    }
	map<int, int> freqMap = help_getFreq(yearlist);	
	int MostSeenYear = help_getMaximumValue(freqMap).first;

	//step 2: find director frequency from Favorites
	vector<string>director;
	for(auto x: Favorites){
        director.push_back(x.getDirector());
    }
	map<string, int> freqMap2 = help_getFreq(director);	
	string MostSeenDirector = help_getMaximumValue(freqMap2).first;


	//step 3: find up to three favorite genres from Favorites

	//step 4: use these criteria (year, director, director) to generate a rec list.
	//may be using different combination of criteria based on the condition of Favorites list
	//open to discussion.. . 



	return rec;

}

