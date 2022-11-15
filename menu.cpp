#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <stdio.h>  
#include <stdlib.h> 

#include "menu.hpp"

Menu::Menu() {
	printMenu();
    int choice = getPrompt();
    processPrompt(choice);
}

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

	for (unsigned i = 0; i < 10; ++i) {
		randIndex = rand() % user.getViewingList().size();

		cout << i + 1 << "." << endl;
		cout << "title: " << user.getViewingList().at(randIndex).getTitle() << endl;
		cout << "year: " << user.getViewingList().at(randIndex).getYear() << endl;
		cout << "director: " << user.getViewingList().at(randIndex).getDirector() << endl;
		cout << "casting: " << user.getViewingList().at(randIndex).getCast() << endl;
		cout << "rating: " << user.getViewingList().at(randIndex).getRating() << endl;
		cout << "imbdid: " << user.getViewingList().at(randIndex).getImdbId() << endl;
		cout << "itemid: " << user.getViewingList().at(randIndex).getItemId() << endl;
		cout << "genre: ";
		for (auto genre : user.getViewingList().at(randIndex).getGenreList()) {cout << genre << " ";} 
		cout << endl;
		cout << "--------------------------------------------------" << endl;

		user.removeFromViewingList(randIndex);
	}
}