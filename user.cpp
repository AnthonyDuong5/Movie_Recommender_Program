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

	//part 1: find year frequency
	vector<int> yearlist;
	for(auto x: Favorites){
        yearlist.push_back(x.getYear());
    }
	map<int, int> freqMap = help_getFreq(yearlist);	
	int MostSeenYear = getMaximumValue(freqMap).first;

	//part 2: find director frequency
	vector<string>director;
	for(auto x: Favorites){
        director.push_back(x.getDirector());
    }
	map<string, int> freqMap2 = help_getFreq(director);	
	string MostSeenDirector = getMaximumValue(freqMap2).first;



	return rec;

}
