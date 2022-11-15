#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <stdio.h>  
#include <stdlib.h> 

#include "json/json.hpp"
#include "movie.hpp"
#include "movieList.hpp"
#include "user.hpp"

using namespace std;

User::User(){
	movieList MovieDatabase;
	MovieDatabase.readMovieListFiles();
	ViewingList = DefaultList = MovieDatabase.returnList();
	UserName = "user1";		//we could ask the username later, doesn't matter much.
    printMenu();
    int choice = getPrompt();
    processPrompt(choice);
}

void User::printMenu(){
	//first output some prompt
	cout << "Please Select An Option Below (1-5)" << endl;
	cout << "1) View Random Movies.\n"
	     << "2) Search Movie(s).\n" 
		 << "3) Add Movie to Favorites.\n" 
		 << "4) Get Recommendations.\n"
		 << "5) Quit.\n";
}

int User::getPrompt(){
	int userPrompt;
	cin >> userPrompt;
	//this also validates input
	while (userPrompt < 1 || userPrompt > 5){
		cout << "Invalid Choice. Please enter a number between 1 to 5." << endl;
		printMenu();
		cin >> userPrompt;
	}
	return userPrompt;
}

void User::processPrompt(const int& prompt){
	if (prompt == 1) printTenRandomMovies();
}

void User::printTenRandomMovies() {
	unsigned randIndex;

	for (unsigned i = 0; i < 10; ++i) {
		randIndex = rand() % ViewingList.size();

		cout << i + 1 << "." << endl;
		cout << "title: " << ViewingList.at(randIndex).getTitle() << endl;
		cout << "year: " << ViewingList.at(randIndex).getYear() << endl;
		cout << "director: " << ViewingList.at(randIndex).getDirector() << endl;
		cout << "casting: " << ViewingList.at(randIndex).getCast() << endl;
		cout << "rating: " << ViewingList.at(randIndex).getRating() << endl;
		cout << "imbdid: " << ViewingList.at(randIndex).getImdbId() << endl;
		cout << "itemid: " << ViewingList.at(randIndex).getItemId() << endl;
		cout << "genre: ";
		for (auto genre : ViewingList.at(randIndex).getGenreList()) {cout << genre << " ";} 
		cout << endl;
		cout << "--------------------------------------------------" << endl;

		ViewingList.erase(ViewingList.begin() + randIndex);
	}
}