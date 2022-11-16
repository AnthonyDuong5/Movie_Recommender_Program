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
	if (prompt == 2) searchMovies();
}

void Menu::printTenRandomMovies() {
	//unsigned randIndex;

	// for (unsigned i = 0; i < 10; ++i) {
	// 	randIndex = rand() % user.getViewingList().size();

	// 	cout << i + 1 << "." << endl;
	// 	cout << "title: " << user.getViewingList().at(randIndex).getTitle() << endl;
	// 	cout << "year: " << user.getViewingList().at(randIndex).getYear() << endl;
	// 	cout << "director: " << user.getViewingList().at(randIndex).getDirector() << endl;
	// 	cout << "casting: " << user.getViewingList().at(randIndex).getCast() << endl;
	// 	cout << "rating: " << user.getViewingList().at(randIndex).getRating() << endl;
	// 	cout << "imbdid: " << user.getViewingList().at(randIndex).getImdbId() << endl;
	// 	cout << "itemid: " << user.getViewingList().at(randIndex).getItemId() << endl;
	// 	cout << "genre: ";
	// 	for (auto genre : user.getViewingList().at(randIndex).getGenreList()) {cout << genre << " ";} 
	// 	cout << endl;
	// 	cout << "--------------------------------------------------" << endl;

	// 	user.removeFromViewingList(randIndex);
	// }
}

void Menu::searchMovies() {

	movieList MovieDatabase;
	string movieTitle;
	double movieRatingOne;
	double movieRatingTwo;
	int movieYearOne;
	int movieYearTwo;
	Genre movieGenre;
	
	vector<movie> filteredList;

	MovieDatabase.readMovieListFiles();

	char choice; char selection;

	do
	{
		cout << "-------------------" << endl;
		cout << "Movie Filter Selection: \n";
		cout << "1) Begin Filtering \n"
			 << "2) **Temporary Option** Print List \n"
			 << "3) **Tentative** Clear Filter \n"
			 << "4) Return to Menu \n";
		cin >> choice;
		cout << "------------------" << endl;
		switch (choice) {
		case '1':
			cout << "Enter a Movie Title? (Y/N): ";
			cin >> selection;
			if(selection == 'Y'){
				cout << "Enter Movie Title: ";
				cin.ignore(255,'\n');
				getline(cin, movieTitle);
				MovieDatabase.searchMovieTitle(movieTitle);
				if(filteredList.size() == 0)
					filteredList = MovieDatabase.returnSortedList();

				//cout << filteredList.size() << endl;  making sure filteredList is updated
			}
			
			cout << "Enter a Rating Range (1-5)? (Y/N): ";
			cin >> selection;
			if(selection == 'Y') {
				do
				{
					cout << "Enter First Rating (Lowest): ";
					cin >> movieRatingOne;
					cout << "Enter Second Rating (Highest): ";
					cin >> movieRatingTwo;
					if(movieRatingOne > movieRatingTwo)
						cout << "First rating input is larger than the second. Please try again." << endl;
				}while (movieRatingOne > movieRatingTwo);

				if(filteredList.size() == 0) {
					MovieDatabase.searchByRatings(movieRatingOne, movieRatingTwo);
					filteredList = MovieDatabase.returnSortedList();
				}
				// else {
				// 	MovieDatabase.sortedlist = filteredList;
				// 	MovieDatabase.searchByRatings(movieRatingOne, movieRatingTwo);
				// 	filteredList = MovieDatabase.returnSortedList();
				// }
			}

			cout << "Enter a Year Range? (Y/N): ";
			cin >> selection;
			if(selection == 'Y') {
				do
				{
					cout << "Enter First Year (Oldest): ";
					cin >> movieYearOne;
					cout << "Enter Second Year (Latest): ";
					cin >> movieYearTwo;
					if(movieYearOne > movieYearTwo)
						cout << "First year input is larger than the second. Please try again." << endl;
				}while (movieYearOne > movieYearTwo);

					if(filteredList.size() == 0) {
						MovieDatabase.searchYearRange(movieYearOne, movieYearTwo);
						filteredList = MovieDatabase.returnSortedList();
					}
					// else {
					// MovieDatabase.sortedlist = filteredList;
					// MovieDatabase.searchYearRange(movieYearOne, movieYearTwo);
					// filteredList = MovieDatabase.returnSortedList();
					// }
				}
			cout << "Enter a Genre? (Y/N)" << endl;
			cin >> selection;
			if(selection == 'Y') {
				cout << "Work in progress..." << endl;
			}
			
			break;
		case '2':
			 if(filteredList.size()==0)
			 	cout << "Empty List \n";
			 else{
				for (unsigned i = 0; i < filteredList.size(); ++i) {
				cout << "--------------------------------------------------" << endl;
				cout << "title: " << filteredList.at(i).getTitle() << endl;
				cout << "year: " << filteredList.at(i).getYear() << endl;
				cout << "director: " << filteredList.at(i).getDirector() << endl;
				cout << "casting: " << filteredList.at(i).getCast() << endl;
				cout << "rating: " << filteredList.at(i).getRating() << endl;
				cout << "imbdid: " << filteredList.at(i).getImdbId() << endl;
				cout << "itemid: " << filteredList.at(i).getItemId() << endl;
				cout << "genre: ";
				for (auto genre : filteredList.at(i).getGenreList()) {cout << genre << " ";} 
				cout << endl;
				cout << "--------------------------------------------------" << endl;
				}
			 }
			break;
		case '4':
			cout << "Returning to Main Menu" << endl;
			break;
		default:
			cout << "Invalid Choice. Please enter a number between 1 and 3" << endl;
		}


	}while (choice != '4');
	
}