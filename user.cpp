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



// void User::printMenu(){
// 	//first output some prompt
// 	cout << "Please Select An Option Below (1-5)" << endl;
// 	cout << "1) View Random Movies.\n"
// 	     << "2) Search Movie(s).\n" 
// 		 << "3) Add Movie to Favorites.\n" 
// 		 << "4) Get Recommendations.\n"
// 		 << "5) Quit.\n";
// }

// int User::getPrompt(){
// 	int userPrompt;
// 	cin >> userPrompt;
// 	//this also validates input
// 	while (userPrompt < 1 || userPrompt > 5){
// 		cout << "Invalid Choice. Please enter a number between 1 to 5." << endl;
// 		printMenu();
// 		cin >> userPrompt;
// 	}
// 	return userPrompt;
// }

// void User::processPrompt(const int& prompt){
// 	if (prompt == 1) printTenRandomMovies();
// }

// void User::printTenRandomMovies() {
// 	unsigned randIndex;

// 	for (unsigned i = 0; i < 10; ++i) {
// 		randIndex = rand() % ViewingList.size();

// 		cout << i + 1 << "." << endl;
// 		cout << "title: " << ViewingList.at(randIndex).getTitle() << endl;
// 		cout << "year: " << ViewingList.at(randIndex).getYear() << endl;
// 		cout << "director: " << ViewingList.at(randIndex).getDirector() << endl;
// 		cout << "casting: " << ViewingList.at(randIndex).getCast() << endl;
// 		cout << "rating: " << ViewingList.at(randIndex).getRating() << endl;
// 		cout << "imbdid: " << ViewingList.at(randIndex).getImdbId() << endl;
// 		cout << "itemid: " << ViewingList.at(randIndex).getItemId() << endl;
// 		cout << "genre: ";
// 		for (auto genre : ViewingList.at(randIndex).getGenreList()) {cout << genre << " ";} 
// 		cout << endl;
// 		cout << "--------------------------------------------------" << endl;

// 		ViewingList.erase(ViewingList.begin() + randIndex);
// 	}
// }


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
