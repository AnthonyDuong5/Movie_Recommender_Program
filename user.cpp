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
	vector<string>directorlist;
	vector<Genre> genreslist;

	//storing each critera into its vector
	for(auto x: Favorites){
        yearlist.push_back(x.getYear());
		directorlist.push_back(x.getDirector());
		for(auto y: x.genre_list){
			genreslist.push_back(y);
		}
    }
	//find #1 year
	map<int, int> freqMap = help_getFreq(yearlist);	
	int MostSeenYear = help_getMaximumValue(freqMap).first;

	//find #1 director
	map<string, int> freqMap2 = help_getFreq(directorlist);	
	string MostSeenDirector = help_getMaximumValue(freqMap2).first;

	//find #3 genres
	map<Genre, int> freqMap3 = help_getFreq(genreslist);	
	Genre MostSeenGenres1 = help_getMaximumValue(freqMap3).first;
	freqMap3.erase(MostSeenGenres1);
	Genre MostSeenGenres2 = help_getMaximumValue(freqMap3).first;
	freqMap3.erase(MostSeenGenres2);
	Genre MostSeenGenres3 = help_getMaximumValue(freqMap3).first;
	freqMap3.erase(MostSeenGenres3);


	//step 4: use these criteria (year, director, director) to generate a rec list.
	//may be using different combination of criteria based on the condition of Favorites list
	//open to discussion.. . 



	return rec;

}

