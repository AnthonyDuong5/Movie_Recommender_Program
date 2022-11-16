#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <stdio.h>  
#include <stdlib.h> 

#include "menu.hpp"
using namespace std;

Menu::Menu() {
	printMenu();
    int choice = getPrompt();
    processPrompt(choice);
	// repeat();
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
	if (prompt == 3) addToFavorites();
	if (prompt == 5) return;
	printMenu();
	processPrompt(getPrompt());
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
		PrintedList.push_back(user.getViewingList().at(randIndex));
		optionTracker = 1;
		user.removeFromViewingList(randIndex);
	}
}



void Menu::addToFavorites(){
	cout << "Select a movie you want to add to favorites." << endl;
	if (optionTracker == 1){
		cout << "To add movies from the random list displayed above, please enter a number for the movies (1-10)." << endl;
		cout << "To add a different movie, please return to main menu. To return, please type: Return" << endl;
		string mChoice = "";
		int mNum = 0;
		cin >> mChoice;

		// using transform() function and ::tolower in STL
    	transform(mChoice.begin(), mChoice.end(), mChoice.begin(), ::tolower);
		//if user chooses to select a movie from random generator and add to fav, we run this.
		if (mChoice != "return"){
			mNum = stoi(mChoice);
			while (mNum < 1 || mNum > 10){
				cout << "Invalid Choice. Please enter a number between 1 to 10." << endl;
				cin >> mNum;
			}
			user.AddToFavoriteList(PrintedList.at(mNum-1));
			cout << "Add another movie? (Y/N)" << endl;
			char u1Choice ;
			cin >> u1Choice;
			if (u1Choice == 'Y' || u1Choice == 'y'){
				addToFavorites();
			}
			else if (u1Choice == 'N' || u1Choice == 'n'){
				return;
			}
			else {
				cout << "Invalid Choice. Please enter either Y/y or N/n" << endl;
			}
			PrintedList.clear();						//clears printedList.
		}
		///////////////////
		//error here......
		else if (mChoice == "return"){
			repeat();
		}

		cout << "Added to Favorites." << endl;
		cout << "You have " << user.getFavoritesList().size() << " movies in your Favorites List." << endl;
		for (int i = 0; i < user.getFavoritesList().size(); ++i){
			cout << user.getFavoritesList().at(i).getTitle() << endl;
		}	
	}
	else {
		searchForMovieByTitle();
	}	
	
	// optionTracker = 3;	
}

//need help here
void Menu::searchForMovieByTitle(){
	
	// string searchName = "";
	// cout << "Enter a name to search. " << endl;
	// cin >> searchName;
	// getline(cin, searchName);			//when i ran ./test, it doesn't seem to take in anything.
	// cout << "Searching for movies with \"" << searchName << "\"" << " in their name" << endl;
	cin.ignore();
	string line;
	cout << "Enter a name to search. " << endl;
	getline(cin, line);
	cout << endl;
	cout << "Searching for movies with \"" << line << "\"" << " in their name" << endl;
	
	cout << user.getUserFavList().returnList().size() << endl;
	cout << user.getUserFavList().returnSortedList().size() << endl;
	user.getUserFavList().searchMovieTitle(line);
	// user.getUserFavList().printMovies();
	cout << user.getUserFavList().returnSortedList().size() << endl;
	
	// user.getUserFavList().searchMovieTitle(line);
	// PrintedList = user.getUserFavList().returnSortedList();
	// user.getUserFavList().printMovies();
	
	// //if there are more than 1 search results, we will ask user to enter number of movie they want to add.
	// if (user.getUserFavList().returnSortedList().size() > 1){
	// 	cout << "Please enter a number for the movie you want to add." << endl;
	// 	int searchSize = user.getUserFavList().returnSortedList().size();
	// 	int userSearchChoice = 0;
	// 	cin >> userSearchChoice;
	// 	while (userSearchChoice < 1 || userSearchChoice > searchSize){
	// 		cout << "Invalid Choice. Please enter a number between 1 and " << searchSize << "." << endl;
	// 		cin >> userSearchChoice;
	// 	}
	// 	user.AddToFavoriteList(PrintedList.at(userSearchChoice-1));
	// }
	cout << "End of List" << endl;
}

void Menu::getCriteria(){

}