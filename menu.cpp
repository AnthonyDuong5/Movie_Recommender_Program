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
	// printMenu();
    // int choice = getPrompt();
    // processPrompt(choice);
	// user.ClearTrackList();
	// repeat();
	runMenu();
}
void Menu::runMenu(){
	while (optionTracker != 7){
		printMenu();
		int choice = getPrompt();
		processPrompt(choice);
		user.ClearTrackList();
	}
	
}
void Menu::printMenu(){
	//first output some prompt
	cout << "Please Select An Option Below (1-7)" << endl;
	cout << "1) View Random Movies.\n"
	     << "2) Browse Category\n" 
		 << "3) Search By Title\n" 
		 << "4) Advanced Movie Search\n"
		 << "5) Get Movie Recommendations\n"
		 << "6) Show Favorites List\n"
		 << "7) Quit.\n";
}

int Menu::getPrompt(){
	
	int userPrompt;
	cin >> userPrompt;
	//this validates chars/strings as invalid input
	while (cin.fail()) {
		//Not an int.
		cout << "Please enter a number from 1 to 7." << endl;
		printMenu();
		cin.clear();
		cin.ignore(256, '\n');
		cin >> userPrompt;
	}

	//this also validates input (integers)
	while (userPrompt < 1 || userPrompt > 7){
		cout << "Invalid Choice. Please enter a number between 1 to 5." << endl;
		printMenu();
		cin >> userPrompt;
		while (cin.fail()) {
			//Not an int.
			cout << "Please enter a number from 1 to 6." << endl;
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
	if (prompt == 2) printFiveByCategories();

	if (prompt == 4) advancedMovieFilter();

	if (prompt == 6) printFavorites();
	if (prompt == 7) {
		optionTracker = 7;
		return;
	}
}

void Menu::printTenRandomMovies() {
	optionTracker = 1;
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
	
	string addChoice;

	cout << "Add any of the Movies to Favorites? ";
	// cin >> addChoice;
	bool YorN;
	// cout << "------------------" << endl;
	YorN = promptYesOrNo(addChoice);
	if (YorN){
		addToFavorites();
	}

	// printMenu();
	// processPrompt(getPrompt());
	return;
}

void Menu::printFiveByCategories(){
	optionTracker = 2;
	cout << "Here's a list of some movies you might be interested in.\n" << endl;
	movieList defaultDatabase;
	defaultDatabase.readMovieListFiles();
	
	vector<movie>actionGenre = defaultDatabase.returnList();
	vector<movie>comedyGenre = defaultDatabase.returnList();
	vector<movie>dramaGenre = defaultDatabase.returnList();
	vector<movie>horrorGenre = defaultDatabase.returnList();
	vector<movie>romanceGenre = defaultDatabase.returnList();
	vector<movie> newList;
	int genreCounter = 0;
	int printcounter = 0;
	string mGenre;

	//for action
	actionGenre = defaultDatabase.searchByGenre(2, actionGenre);
	
	comedyGenre = defaultDatabase.searchByGenre(5, comedyGenre);
	
	dramaGenre = defaultDatabase.searchByGenre(8, dramaGenre);
	
	horrorGenre = defaultDatabase.searchByGenre(11, horrorGenre);
	
	romanceGenre = defaultDatabase.searchByGenre(15, romanceGenre);
	
	unsigned randNum;
	while (genreCounter <5){
		if (genreCounter == 0){
			cout << "=============================================" << endl;
			cout << "ACTION MOVIES" << endl;
			cout << "=============================================" << endl;
		}
		else if (genreCounter == 1){
			cout << "=============================================" << endl;
			cout << "COMEDY MOVIES" << endl;
			cout << "=============================================" << endl;
		}
		else if (genreCounter == 2){
				cout << "=============================================" << endl;
				cout << "DRAMA MOVIES" << endl;
				cout << "=============================================" << endl;
		}
		else if (genreCounter == 3){
				cout << "=============================================" << endl;
				cout << "HORROR MOVIES" << endl;
				cout << "=============================================" << endl;		
		}

		else if (genreCounter == 4){
				cout << "=============================================" << endl;
				cout << "ROMANCE MOVIES" << endl;
				cout << "=============================================" << endl;
		}
		for (unsigned i = 0; i < 5; ++i){
			if (genreCounter == 0){
				
				randNum = rand() % actionGenre.size();
				movie rMovie = actionGenre.at(randNum);
				rMovie.printMovie();
				newList.push_back(rMovie);
				user.AddToTrackList(rMovie);
			}
			else if (genreCounter == 1){
				
				randNum = rand() % comedyGenre.size();
				movie rMovie = comedyGenre.at(randNum);
				rMovie.printMovie();
				newList.push_back(rMovie);
				user.AddToTrackList(rMovie);
			}
			else if (genreCounter == 2){
				
				randNum = rand() % dramaGenre.size();
				movie rMovie = dramaGenre.at(randNum);
				rMovie.printMovie();
				newList.push_back(rMovie);
				user.AddToTrackList(rMovie);
			}
			else if (genreCounter == 3){
				
				randNum = rand() % horrorGenre.size();
				movie rMovie = horrorGenre.at(randNum);
				rMovie.printMovie();
				newList.push_back(rMovie);
				user.AddToTrackList(rMovie);
			}
			else if (genreCounter == 4){
				
				randNum = rand() % romanceGenre.size();
				movie rMovie = romanceGenre.at(randNum);
				rMovie.printMovie();
				newList.push_back(rMovie);
				user.AddToTrackList(rMovie);
			}
		}
		++genreCounter;
	}
	cout << "Add any of the movies to favorites?" << endl;
	string u5Prompt;
	
	bool toAdd = promptYesOrNo(u5Prompt);
	if (toAdd) {
		addToFavorites();
	}
}



void Menu::advancedMovieFilter() {
	optionTracker = 4;
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
				//updated tracking list to equal to filtered list
				for (unsigned i = 0; i < filteredList.size(); ++i){
					movie curMovie = filteredList.at(i);
					user.AddToTrackList(curMovie);
				}
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
					filteredList.at(i).printMovie();
				}
				//this will be used to validate in AddToFav
				cout << "Add any of the movies to favorites?" << endl;
				string uPrompt;
				// cin >> uPrompt;
				bool toAdd = promptYesOrNo(uPrompt);
				if (toAdd) {
					addToFavorites();
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
			return;	
		default:
			cout << "Invalid Choice. Please enter a number between 1 and 4" << endl;
		}


	}while (choice != '4');
	
	optionTracker = 2;
}


void Menu::addToFavorites(){

	//this checks if user used adv filter but did not print the movies. so we will have to output the movies for them
	if (optionTracker == 1){
		cout << "Adding to Favorites from a list of random movies. " << endl;
	}
	else if (optionTracker == 2){
		cout << "Adding to Favorites from Browsed Categories. " << endl;
	}
	else if (optionTracker == 3){
		cout << "Adding to Favorites from Searched List. " << endl;
	}
	else if (optionTracker == 4){
		cout << "Adding to Favorites from Advanced Search." << endl;
	}

	cout << "Enter the itemId of the movie you want to add from the list displayed above:";
	int inputID;
	cin >> inputID;
	while (cin.fail()) {
		//input is not an int.
		cout << "Please enter a valid itemId." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> inputID;
	}
	//found is a bool that will be set to true if movie to add is already in favorites
	bool found = false;
	for (int i = 0; i < user.ReturnTrackList().size(); ++i){
		//if the movie has been found inside the track list
		if (inputID == user.ReturnTrackList().at(i).getItemId()){
			found = true;
			cout << user.ReturnTrackList().at(i).getTitle() << " has been selected. ";
			//this if statement means the movie has not been in favorites
			if (checkInFavorites(inputID) == false){
				cout << "Would you like to add this movie?";
				string confirmAdd;
				bool YorN = promptYesOrNo(confirmAdd);
				//reconfirm if they want to add, if yes, we add
				if (YorN){
					movie fMovie = user.ReturnTrackList().at(i);
					user.AddToFavoriteList(fMovie);
					//user.getFavoritesList().push_back(user.ReturnTrackList().at(i));
					
					cout << user.ReturnTrackList().at(i).getTitle() << " has been added to Favorites." << endl;
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
						runMenu();
						break;
					}
				}	
			}
			//we see the movie in favorites, so we say this and do not add it to the fav list again.
			else{
				cout << user.ReturnTrackList().at(i).getTitle() << "is already in Favorites." << endl;
			}
		}
	}
	//if the movie was not found(itemid is wrong), we output an error message and 
	if (found == false) {
		cout << "Movie not found. Please enter a valid ItemId." << endl;
	}

	cout << "There are currently " << user.getFavoritesList().size() << " movies in your Favorites List. " << endl;
	cout << "Add a different movie? ";
	string u2Choice;
	bool u2ChoiceYorN = promptYesOrNo(u2Choice);
	//if so, we will rerun the addToFavorites() func.
	if (u2ChoiceYorN){
		addToFavorites();	
	}	
	//otherwise, we will return to menu
	else {
		cout << "Now returning to Previous Menu..." << endl;
		return;
	}
}

bool Menu::checkInFavorites(const int mID){
	for (int i = 0; i < user.getFavoritesList().size(); ++i){
		if (user.getFavoritesList().at(i).getItemId() == mID){
			return true;				//this mean movie is already in favorites
		}
	}
	return false;
}

void Menu::printFavorites(){
	cout << "==================================================" << endl;
	cout << "------------------Favorites List------------------" << endl;
	cout << "==================================================" << endl;
	vector<movie> fav = user.getFavoritesList();
	for (unsigned i = 0; i < fav.size(); ++i){
		fav.at(i).printMovie();
	}
	cout << "==================================================" << endl;
	cout << "-------------------End Of List--------------------" << endl;
	cout << "==================================================" << endl;
	cout << "Total of " << fav.size() << " movies in Favorites." << endl;
	cout << "==================================================" << endl;
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