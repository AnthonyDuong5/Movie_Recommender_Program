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
		movie curMovie = user.getViewingList().at(randIndex);
		cout << i + 1 << "." << endl;
		curMovie.printMovie();

		//added this line to track results
		user.AddToTrackList(curMovie);
		
		user.removeFromViewingList(randIndex);
	}
	cout << "Return Track List has " << user.ReturnTrackList().size() << " movies." << endl;
	optionTracker = 1;
	string addChoice;

	cout << "Add any of the Movies to Favorites? ";
	// cin >> addChoice;
	bool YorN;
	// cout << "------------------" << endl;
	YorN = promptYesOrNo(addChoice);
	if (YorN){
		addToFavorites();
	}

	printMenu();
	processPrompt(getPrompt());
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
				//added this line to track results
				user.ReturnTrackList().push_back(filteredList.at(i));
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


void Menu::addToFavorites(){
	cout << "Enter the itemId of the movie you want to add." << endl;
	int inputID;
	cin >> inputID;
	while (cin.fail()) {
		//Not an int.
		cout << "Please enter a valid itemId." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> inputID;
	}
	cout << "Return Track List has " << user.ReturnTrackList().size() << "movies." << endl;
	for (int i = 0; i < user.ReturnTrackList().size(); ++i){
		//if the movie has been found inside the track lis
		if (inputID == user.ReturnTrackList().at(i).getItemId()){
			cout << user.ReturnTrackList().at(i).getTitle() << "has been selected.";
			//this if statement means the movie has not been in favorites
			if (checkInFavorites(inputID) == false){
				cout << "Would you like to add this movie?";
				string confirmAdd;
				bool YorN = promptYesOrNo(confirmAdd);
				//reconfirm if they want to add, if yes, we add
				if (YorN){
					user.getFavoritesList().push_back(user.ReturnTrackList().at(i));
					cout << user.ReturnTrackList().at(i).getTitle() << "has been added to Favorites." << endl;
				}
				//else, we as if they want to add a different movie.
				
				else {
					cout << "Add a different movie? ";
					string uChoice;
					bool uChoiceYorN = promptYesOrNo(uChoice);
					//if so, we will rerun the addToFavorites() func.
					if (uChoiceYorN){
						addToFavorites();
					}
					//otherwise, we will return to menu
					else {
						cout << "Now returning to Main Menu..." << endl;
						Menu();
						break;
					}
				}	
			}
			//we see the movie in favorites, so we say this and do not add it to the fav list again.
			else{
				cout << user.ReturnTrackList().at(i).getTitle() << "is already in Favorites." << endl;
				
				cout << "Add a different movie? ";
					string u2Choice;
					bool u2ChoiceYorN = promptYesOrNo(u2Choice);
					//if so, we will rerun the addToFavorites() func.
					if (u2ChoiceYorN){
						addToFavorites();
					}
					//otherwise, we will return to menu
					else {
						cout << "Now returning to Main Menu..." << endl;
						Menu();
						break;
					}
			}
		}
	}
	cout << "There are currently " << user.getFavoritesList().size() << " movies in your Favorites List. " << endl;
	cout << "Add another movie to Favorites? ";
	string u3Choice;
	bool u3ChoiceYorN;
	u3ChoiceYorN = promptYesOrNo(u3Choice);
	if (u3ChoiceYorN){
		addToFavorites();
	}
	// optionTracker = 3;	
}

bool Menu::checkInFavorites(const int mID){
	for (int i = 0; i < user.getFavoritesList().size(); ++i){
		if (user.getFavoritesList().at(i).getItemId() == mID){
			return true;				//this mean movie is already in favorites
		}
	}
	return false;
}

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