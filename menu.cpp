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
	     << "2) Advanced Movie Filter.\n" 
		 << "3) Add Movie to Favorites.\n" 
		 << "4) Get Recommendations.\n"
		 << "5) Quit.\n";
}

int Menu::getPrompt(){
	
	int userPrompt;
	cin >> userPrompt;
	//this validates chars/strings as invalid input
	while (cin.fail()) {
		//Not an int.
		cout << "Please enter a number from 1 to 5." << endl;
		printMenu();
		cin.clear();
		cin.ignore(256, '\n');
		cin >> userPrompt;
	}

	//this also validates input (integers)
	while (userPrompt < 1 || userPrompt > 5){
		cout << "Invalid Choice. Please enter a number between 1 to 5." << endl;
		printMenu();
		cin >> userPrompt;
		while (cin.fail()) {
			//Not an int.
			cout << "Please enter a number from 1 to 5." << endl;
			printMenu();
			cin.clear();
			cin.ignore(256, '\n');
			cin >> userPrompt;
		}
	}
	return userPrompt;
}

void Menu::processPrompt(const int& prompt){
	if (prompt == 1) printTenRandomMovies();
	if (prompt == 2) advancedMovieFilter();

	if (prompt == 5) return;
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
	optionTracker = 1;
}

void Menu::advancedMovieFilter() {

	movieList MovieDatabase;
	string movieTitle;
	double movieRatingOne = 0.0;
	double movieRatingTwo = 0.0;
	int movieYearOne = 0;
	int movieYearTwo = 0;
	int movieGenre = 0;

	vector <movie> filteredList;
	MovieDatabase.readMovieListFiles();

	char choice; 
	string selection;
	bool yesOrNo;

	do
	{
		cout << "-------------------" << endl;
		cout << "Advanced Movie Filter (1-4) \n";
		cout << "1) Begin Filtering \n"
			 << "2) Print Out Movies \n"
			 << "3) Clear Filter \n"
			 << "4) Return to Menu \n";
		cin >> choice;
		cout << "------------------" << endl;
		switch (choice) {
		case '1':
			if(filteredList.size() == 0) {	
	
			//TITLE
			cout << "Enter a Movie Title? ";
			yesOrNo = promptYesOrNo(selection);
			if(yesOrNo) {
				cout << "Enter Movie Title: ";
				cin.ignore(255,'\n');
				getline(cin, movieTitle);
				if(filteredList.size() == 0)
				filteredList = MovieDatabase.searchMovieTitle(movieTitle, filteredList);
			}

			//RATING
			cout << "Enter a Rating Range (1-5)? ";
			yesOrNo = promptYesOrNo(selection);
			if(yesOrNo) {
				do
				{
					cout << "Enter First Rating (Lowest): ";
					cin >> movieRatingOne;
						while (cin.fail()) {
							cout << "Please enter a valid rating value (1-5)." << endl;
							cin.clear();
							cin.ignore(256, '\n');
							cout << "Enter First Rating (Lowest): ";
							cin >> movieRatingOne;
						}
					cout << "Enter Second Rating (Highest): ";
					cin >> movieRatingTwo;
						while (cin.fail()) {
							cout << "Please enter a valid rating value (1-5)." << endl;
							cin.clear();
							cin.ignore(256, '\n');
							cout << "Enter Second Rating (Highest): ";
							cin >> movieRatingTwo;
						}
					if(movieRatingOne > movieRatingTwo)
						cout << "First rating input is larger than the second. Please try again." << endl;
				}while (movieRatingOne > movieRatingTwo);
					filteredList = MovieDatabase.searchByRatings(movieRatingOne, movieRatingTwo, filteredList);
			}

			//YEAR
			cout << "Enter a Year Range? ";
			yesOrNo = promptYesOrNo(selection);
			if(yesOrNo) {
				do
				{
					cout << "Enter First Year (Oldest): ";
					cin >> movieYearOne;
						while (cin.fail()) {
							cout << "Please enter a valid year." << endl;
							cin.clear();
							cin.ignore(256, '\n');
							cout << "Enter First Year (Oldest): ";
							cin >> movieYearOne;
						}
					cout << "Enter Second Year (Latest): ";
					cin >> movieYearTwo;
						while (cin.fail()) {
							cout << "Please enter a valid year." << endl;
							cin.clear();
							cin.ignore(256, '\n');
							cout << "Enter Second Year (Latest): ";
							cin >> movieYearTwo;
						}
					if(movieYearOne > movieYearTwo)
						cout << "First year input is larger than the second. Please try again." << endl;
				}while (movieYearOne > movieYearTwo);
					MovieDatabase.searchYearRange(movieYearOne, movieYearTwo, filteredList);
				}

			//GENRE
			cout << "Enter a Genre? ";
			yesOrNo = promptYesOrNo(selection);
			if(yesOrNo) {
				do{
					cout << "----------------------------------------------------" << endl;
					cout << "Enter the number that corresponds to desired Genre: " << endl;
					cout << "1) Adventure || 2) Action     || 3) Animation      || 4) Children \n"
						<< "5) Comedy    || 6) Crime      || 7) Documentaries  || 8) Drama \n"
						<< "9) Fantasy   || 10) FilmNoir  || 11) Horror        || 12) IMAX \n"
						<< "13) Musical  || 14) Mystery   || 15) Romance       || 16) SciFi \n"
						<< "17) Thriller || 18) War       || 19) Western \n";
					cout << "Choice: ";
					cin >> movieGenre;
						while (cin.fail()) {
						cout << "Please enter a number from 1 to 19." << endl;
						cin.clear();
						cin.ignore(256, '\n');
						cin >> movieGenre;
						}
						if(movieGenre < 1 || movieGenre > 19)
							cout << "Please enter a number from 1 to 19." << endl;
				}while(movieGenre < 1 || movieGenre > 19);
				MovieDatabase.searchByGenre(movieGenre, filteredList);
			}

			getCriteria(movieTitle, movieRatingOne, movieRatingTwo, movieYearOne, movieYearTwo, movieGenre);

			if (filteredList.size() > 0) {
			cout << filteredList.size() << " movies found that meet your criteria! Enter '2' to view movies." << endl;
			}
			else
				cout << "No movies found under the criteria given." << endl;

			}
			else
				cout << "You need to clear out the filter criteria before refiltering movies." << endl;
			break;

		case '2':
			 if(filteredList.size()==0)
			 	cout << "No movies found under the criteria given or filter is empty. \n";
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
		case '3':
				if(filteredList.size() == 0)
					cout << "Filter has already been cleared." << endl;
				else {
					filteredList.clear();
					cout << "Filter is clear." << endl;
				}
			break;

		case '4':
			Menu();
			break;
		default:
			cout << "Invalid Choice. Please enter a number between 1 and 4" << endl;
		}


	}while (choice != '4');
	
	optionTracker = 2;
}


// void Menu::addToFavorites(){
// 	cout << "Select a movie you want to add to favorites." << endl;
// 	if (optionTracker == 1){
// 		cout << "To add movies from the random list displayed above, please enter the itemid number for the movies (1-10)." << endl;
// 		cout << "To add a different movie, please return to main menu. To return, please type: Return" << endl;
// 		string mChoice = "";
// 		int mNum = 0;
// 		cin >> mChoice;

// 		// using transform() function and ::tolower in STL
//     	transform(mChoice.begin(), mChoice.end(), mChoice.begin(), ::tolower);
// 		//if user chooses to select a movie from random generator and add to fav, we run this.
// 		if (mChoice != "return"){
// 			mNum = stoi(mChoice);
// 			// while (mNum < 1 || mNum > 10){
// 			// 	cout << "Invalid Choice. Please enter a number between 1 to 10." << endl;
// 			// 	cin >> mNum;
// 			// }
			

// 			user.AddToFavoriteList(PrintedList.at(mNum-1));
// 			cout << "Add another movie? (Y/N)" << endl;
// 			char u1Choice ;
// 			cin >> u1Choice;
// 			if (u1Choice == 'Y' || u1Choice == 'y'){
// 				addToFavorites();
// 			}
// 			else if (u1Choice == 'N' || u1Choice == 'n'){
// 				return;
// 			}
// 			else {
// 				cout << "Invalid Choice. Please enter either Y/y or N/n" << endl;
// 			}
// 			PrintedList.clear();						//clears printedList.
// 		}
// 		///////////////////
// 		//error here......
// 		else if (mChoice == "return"){
// 			repeat();
// 		}

// 		cout << "Added to Favorites." << endl;
// 		cout << "You have " << user.getFavoritesList().size() << " movies in your Favorites List." << endl;
// 		for (int i = 0; i < user.getFavoritesList().size(); ++i){
// 			cout << user.getFavoritesList().at(i).getTitle() << endl;
// 		}	
// 	}
// 	else {
// 		searchForMovieByTitle();
// 	}	
	
// 	// optionTracker = 3;	
// }

void Menu::getCriteria(string title, double ratingOne, double ratingTwo, int yearOne, int yearTwo, int genre) {
	cout << "-----------------------" << endl;
	cout << "User's Filter Criteria:" << endl;
	cout << "Movie Title: ";
	if (title.empty())
		cout << "N/A" << endl;
	else
		cout << title << endl;
	cout << "Movie Rating Range: ";
	if (ratingOne == 0.0)
		cout << "N/A" << endl;
	else
		cout << ratingOne << " - " << ratingTwo << endl;
	cout << "Movie Year Range: ";
	if(yearOne == 0)
		cout << "N/A" << endl;
	else
		cout << yearOne << " - " << yearTwo << endl;
	cout << "Movie Genre: ";
	if(genre == 0)
		cout << "N/A" << endl;
	else
		cout << genre << endl;
}

bool Menu::promptYesOrNo(string response) {
	bool YesOrNo;

	do {
	cout << "(Y/N): ";
	cin >> response;
	transform(response.begin(), response.end(), response.begin(), ::toupper);

	if(response == "Y")
		YesOrNo = true;
	else if (response == "N")
		YesOrNo = false;
	else
		cout << "Invalid input, please try again." << endl;

	}while(response != "Y" && response != "N");

	return YesOrNo;

}