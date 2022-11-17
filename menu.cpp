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
	double movieRatingOne = 0.0;
	double movieRatingTwo = 0.0;
	int movieYearOne = 0;
	int movieYearTwo = 0;
	int movieGenre = 0;

	vector <movie> filteredList;
	MovieDatabase.readMovieListFiles();

	char choice; 
	char selection;

	do
	{
		cout << "-------------------" << endl;
		cout << "Movie Filter Selection: \n";
		cout << "1) Begin Filtering \n"
			 << "2) Print Out Movies \n"
			 << "3) Clear Filter \n"
			 << "4) Return to Menu \n";
		cin >> choice;
		cout << "------------------" << endl;
		switch (choice) {
		case '1':
			if(filteredList.size() == 0) {		//if list is empty, able to (re)filter movies
	
			//TITLE
			cout << "Enter a Movie Title? (Y/N): ";
			cin >> selection;
			if(selection == 'Y'){
				cout << "Enter Movie Title: ";
				cin.ignore(255,'\n');
				getline(cin, movieTitle);
				if(filteredList.size() == 0)
					filteredList = MovieDatabase.searchMovieTitle(movieTitle, filteredList);
			} 

			//RATING
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
					filteredList = MovieDatabase.searchByRatings(movieRatingOne, movieRatingTwo, filteredList);
			}

			//YEAR
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
					MovieDatabase.searchYearRange(movieYearOne, movieYearTwo, filteredList);
				}

			//GENRE
			cout << "Enter a Genre? (Y/N): ";
			cin >> selection;
			if(selection == 'Y') {
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
					if(movieGenre < 1 || movieGenre > 19)
						cout << "Invalid input. Please try again." << endl;
				}while(movieGenre < 1 || movieGenre > 19);
				MovieDatabase.searchByGenre(movieGenre, filteredList);
			}
				cout << "-----------------------" << endl;
				cout << "User's Filter Criteria:" << endl;
				cout << "Movie Title: ";
				if (movieTitle.empty())
					cout << "N/A" << endl;
				else
					cout << movieTitle << endl;
				cout << "Movie Rating Range: ";
				if (movieRatingOne == 0.0)
					cout << "N/A" << endl;
				else
					cout << movieRatingOne << " - " << movieRatingTwo << endl;
				cout << "Movie Year Range: ";
				if(movieYearOne == 0)
					cout << "N/A" << endl;
				else
					cout << movieYearOne << " - " << movieYearTwo << endl;
				cout << "Movie Genre: ";
				if(movieGenre == 0)
					cout << "N/A" << endl;
				else
					cout << movieGenre << endl;

				if (filteredList.size() < 0) {
				cout << '\n';
				cout << filteredList.size() << " movies found that meet your criteria! Enter '2' to view movies." << endl;
				}
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
			cout << "Returning to Main Menu" << endl;
			break;
		default:
			cout << "Invalid Choice. Please enter a number between 1 and 4" << endl;
		}


	}while (choice != '4');
	
}
