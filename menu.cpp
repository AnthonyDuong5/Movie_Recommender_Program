#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>  
#include <stdlib.h> 

#include "menu.hpp"

void Menu::printMenu(){
	//first output some prompt
	cout << "Please Select An Option Below (1-5)" << endl;
	cout << "1) View Random Movies.\n"
	     << "2) Search Movie(s).\n" 
		 << "3) Add Movie to Favorites.\n" 
		 << "4) Get Recommendations.\n"
		 << "5) Quit.\n";
}

int Menu::getPrompt(){
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

void Menu::processPrompt(const int& prompt){
	if (prompt == 1) printTenRandomMovies();
}

void Menu::printTenRandomMovies() {
	unsigned randIndex;
	bool alreadyViewed;
    

	for (unsigned i = 0; i < 10; ++i) {
		alreadyViewed = false;
		randIndex = rand() % user1.getDefaultList().size();

		for (unsigned j = 0; j < user1.getViewedList().size(); ++j) {
			if (user1.getViewedList().at(j).getItemId() == user1.getDefaultList().at(randIndex).getItemId()) {
				alreadyViewed = true;
				break;
			}
		}

		if (!alreadyViewed) {
			cout << i + 1 << "." << endl;
			cout << "title: " << user1.getDefaultList().at(randIndex).getTitle() << endl;
			cout << "year: " << user1.getDefaultList().at(randIndex).getYear() << endl;
			cout << "director: " << user1.getDefaultList().at(randIndex).getCast() << endl;
			cout << "rating: " << user1.getDefaultList().at(randIndex).getRating() << endl;
			cout << "imbdid: " << user1.getDefaultList().at(randIndex).getImdbId() << endl;
			cout << "itemid: " << user1.getDefaultList().at(randIndex).getItemId() << endl;
			cout << "genre: ";
			for (auto genre : user1.getDefaultList().at(randIndex).getGenreList()) {cout << genre << " ";} 
			cout << endl;
			cout << "--------------------------------------------------" << endl;
			user1.getViewedList().push_back(user1.getDefaultList().at(randIndex));
		}
	}
}