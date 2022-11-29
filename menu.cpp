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
	if (prompt == 3) searchByTitle();
	if (prompt == 4) advancedMovieFilter();
	if (prompt == 5) getRecommendation();
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
	bool YorN;
	// cout << "------------------" << endl;
	YorN = promptYesOrNo(addChoice);
	if (YorN){
		addToFavorites();
	}
	return;
}

void Menu::printFiveByCategories(){
	optionTracker = 2;
	movieList defaultDatabase;
	defaultDatabase.readMovieListFiles();
	cout << "You can browse a category of movies." << endl;

	cout << "You can: \n"
		 << "1) Select Genres you like \n"
		 << "2) Browse Directly \n"
		 << "Choose an option(1-2):\n";
	int gSelect;
	cin >> gSelect;
	/// DO STUFF HERE
	while (cin.fail()) {
			cout << "Please enter either 1 or 2." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> gSelect;
	}
	if(gSelect < 1 || gSelect > 2){
		cout << "Please enter a number from 1 to 2." << endl;
	}
	//user decides to choose genre:
	if (gSelect == 1){
		cout << "Enter the number that corresponds to desired Genre: " << endl;
		cout << "1) Adventure || 2) Action     || 3) Animation      || 4) Children \n"
			<< "5) Comedy    || 6) Crime      || 7) Documentaries  || 8) Drama \n"
			<< "9) Fantasy   || 10) FilmNoir  || 11) Horror        || 12) IMAX \n"
			<< "13) Musical  || 14) Mystery   || 15) Romance       || 16) SciFi \n"
			<< "17) Thriller || 18) War       || 19) Western \n";

		vector<int>genreChoice;
		int uIn;
		do {
			cin >> uIn;
			while (cin.fail()) {
				cout << "Please enter a number from 1 to 19." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> uIn;
			}
			if(uIn < 1 || uIn > 19){
				cout << "Please enter a number from 1 to 19." << endl;
			}
		}
		while(uIn < 1 || uIn > 19);
		
		vector<movie>userGenre = defaultDatabase.returnList();
		userGenre = defaultDatabase.searchByGenre(uIn, userGenre);
		cout << "You have selected " << defaultDatabase.getGenres().at(uIn-1) << "." << endl;
		cout << "Here are ten movies from the genre you have selected" << endl;
		cout << "=============================================" << endl;
		cout <<  defaultDatabase.getGenres().at(uIn-1) << " Movies " << endl;
		cout << "=============================================" << endl;
		unsigned randNum;
		for (unsigned k = 0; k < 10; ++k){
			randNum = rand() % userGenre.size();
			movie rMovie = userGenre.at(randNum);
			rMovie.printMovie();
					
			user.AddToTrackList(rMovie);
		}
		cout << "Add any of the movies to favorites?" << endl;
		string addPrompt;
		
		bool addToF = promptYesOrNo(addPrompt);
		if (addToF) {
			addToFavorites();
		}
	}

	if (gSelect == 2){
		cout << "Here's a list of some movies you might be interested in.\n" << endl;
		movieList defaultDatabase;
		defaultDatabase.readMovieListFiles();
		
		vector<movie>actionGenre = defaultDatabase.returnList();
		vector<movie>comedyGenre = defaultDatabase.returnList();
		vector<movie>dramaGenre = defaultDatabase.returnList();
		vector<movie>horrorGenre = defaultDatabase.returnList();
		vector<movie>romanceGenre = defaultDatabase.returnList();
		int genreCounter = 0;
		
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
				cout << "----------------ACTION MOVIES----------------" << endl;
				cout << "=============================================" << endl;
			}
			else if (genreCounter == 1){
				cout << "=============================================" << endl;
				cout << "----------------COMEDY MOVIES----------------" << endl;
				cout << "=============================================" << endl;
			}
			else if (genreCounter == 2){
					cout << "=============================================" << endl;
					cout << "----------------DRAMA MOVIES-----------------" << endl;
					cout << "=============================================" << endl;
			}
			else if (genreCounter == 3){
					cout << "=============================================" << endl;
					cout << "----------------HORROR MOVIES----------------" << endl;
					cout << "=============================================" << endl;		
			}

			else if (genreCounter == 4){
					cout << "=============================================" << endl;
					cout << "---------------ROMANCE MOVIES----------------" << endl;
					cout << "=============================================" << endl;
			}
			for (unsigned i = 0; i < 5; ++i){
				if (genreCounter == 0){
					
					randNum = rand() % actionGenre.size();
					movie rMovie = actionGenre.at(randNum);
					rMovie.printMovie();
					
					user.AddToTrackList(rMovie);
				}
				else if (genreCounter == 1){
					
					randNum = rand() % comedyGenre.size();
					movie rMovie = comedyGenre.at(randNum);
					rMovie.printMovie();
					
					user.AddToTrackList(rMovie);
				}
				else if (genreCounter == 2){
					
					randNum = rand() % dramaGenre.size();
					movie rMovie = dramaGenre.at(randNum);
					rMovie.printMovie();
					
					user.AddToTrackList(rMovie);
				}
				else if (genreCounter == 3){
					
					randNum = rand() % horrorGenre.size();
					movie rMovie = horrorGenre.at(randNum);
					rMovie.printMovie();
					
					user.AddToTrackList(rMovie);
				}
				else if (genreCounter == 4){
					
					randNum = rand() % romanceGenre.size();
					movie rMovie = romanceGenre.at(randNum);
					rMovie.printMovie();
					
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

}

void Menu::searchByTitle() {
	optionTracker = 3;
	movieList defaultDatabase;
	defaultDatabase.readMovieListFiles();

	string titleSearched;
	string response;
	vector<movie> searchedTitleList;

	cout << "Enter Movie Title: ";
	cin.ignore(255,'\n');
	getline(cin, titleSearched);
	searchedTitleList = defaultDatabase.searchMovieTitle(titleSearched, searchedTitleList);

	if(searchedTitleList.size() == 0)
		cout << "No movies found with search: '" << titleSearched << "'" << endl;
	else {
		cout << "==================================================" << endl;
		cout << "----------------Beginning Of List-----------------" << endl;
		cout << "==================================================" << endl;
		for (unsigned i = 0; i < searchedTitleList.size(); ++i) {
			movie rMovie = searchedTitleList.at(i);	
			user.AddToTrackList(rMovie);
			searchedTitleList.at(i).printMovie();
		}
		cout << "==================================================" << endl;
		cout << "-------------------End Of List--------------------" << endl;
		cout << "==================================================" << endl;
		cout << searchedTitleList.size() << " movies with search: '" << titleSearched << "'" << endl;
		cout << "==================================================" << endl;
		
		cout << "Add any of the movies to favorites?" << endl;
		bool yesOrNo = promptYesOrNo(response);
		if (yesOrNo) {
			addToFavorites();
		}
	}

}

void Menu::advancedMovieFilter() {
	optionTracker = 4;
	movieList defaultDatabase;

	vector <movie> filteredList;
	defaultDatabase.readMovieListFiles();

	char choice; 
	string selection;
	bool yesOrNo;

	do
	{
		cout << "-------------------" << endl;
		cout << "Advanced Movie Filter (1-4) \n";
		cout << "1) Begin Filtering \n"
			 << "2) View Filtered Movie List \n"
			 << "3) Return to Menu \n";
		cin >> choice;
		cout << "------------------" << endl;
		switch (choice) {
		case '1':
			filteredList.clear();
			if(filteredList.size() == 0) {	
			
			string movieTitle;
			double movieRatingOne = 0.0;
			double movieRatingTwo = 0.0;
			int movieYearOne = 0;
			int movieYearTwo = 0;
			int movieGenre = 0;
	
			//TITLE
			cout << "Enter a Movie Title? ";
			yesOrNo = promptYesOrNo(selection);
			if(yesOrNo) {
				cout << "Enter Movie Title: ";
				cin.ignore(255,'\n');
				getline(cin, movieTitle);
				if(filteredList.size() == 0)
				filteredList = defaultDatabase.searchMovieTitle(movieTitle, filteredList);
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
					filteredList = defaultDatabase.searchByRatings(movieRatingOne, movieRatingTwo, filteredList);
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
					defaultDatabase.searchYearRange(movieYearOne, movieYearTwo, filteredList);
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
				defaultDatabase.searchByGenre(movieGenre, filteredList);
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
			return;	
		default:
			cout << "Invalid Choice. Please enter a number between 1 and 3" << endl;
		}


	}while (choice != '3');
	
}


void Menu::addToFavorites(){

	//this checks if user used adv filter but did not print the movies. so we will have to output the movies for them
	if (optionTracker == 1){
		cout << "Adding to Favorites from a list of random movies." << endl;
	}
	else if (optionTracker == 2){
		cout << "Adding to Favorites from Browsed Categories." << endl;
	}
	else if (optionTracker == 3){
		cout << "Adding to Favorites from Searched List." << endl;
	}
	else if (optionTracker == 4){
		cout << "Adding to Favorites from Advanced Search." << endl;
	}
	else if (optionTracker == 5){
		cout << "Adding to Favorites from Movie Recommendations." << endl;
	}

	int displaySize = user.ReturnTrackList().size();
	int curSize = 0;
	//first we need to check if the movies from track are already in track list.
	//we output number of available movies accordingly.
	//case for only 1 movie in track list
	if (user.ReturnTrackList().size() == 1 && (checkInFavorites(user.ReturnTrackList().front().getItemId()) == false) ){
		cout << user.ReturnTrackList().front().getTitle() << " has been selected. ";
		cout << "Would you like to add this movie? ";
		string confirmAdd;
		bool YorN = promptYesOrNo(confirmAdd);
		//reconfirm if they want to add, if yes, we add
		if (YorN){
			movie fMovie = user.ReturnTrackList().front();
			user.AddToFavoriteList(fMovie);
				//user.getFavoritesList().push_back(user.ReturnTrackList().at(i));
				
			cout << user.ReturnTrackList().front().getTitle() << " has been added to Favorites." << endl;
		}
	}
	else if (user.ReturnTrackList().size() == 1 && (checkInFavorites(user.ReturnTrackList().front().getItemId()) == true)) {
		cout << "This movie is already in Favorites." << endl;
	}
	//case for more than 1 movie
	else {
		while (curSize < displaySize){
			cout << "There are " << countInFavorites() << " movie(s) from the current list that are already in Favorites." << endl;
			cout << "You can add " << displaySize - curSize - countInFavorites() << " movies from the list." << endl;
			cout << "Enter the itemId of the movie you want to add from the list above: ";
			int inputId;
			cin >> inputId;
			while (cin.fail()){
				//input is not an int
				cout << "Please enter a valid itemId." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> inputId;
			}
			//check to see if valid id
			bool foundInTrack = false;
			int trackIndex;
			for (unsigned i = 0; i < user.ReturnTrackList().size(); ++i){
				if (inputId == user.ReturnTrackList().at(i).getItemId()){
					foundInTrack = true;
					trackIndex = i;
					cout << user.ReturnTrackList().at(i).getTitle() << " has been selected. ";
					break;
				}
			}
			//foundInFav is a bool that will be set to true if movie to add is already in favorites
			bool foundInFav = checkInFavorites(inputId);
			//we check if item is already in favorites. if it isn't, we prompt
			if (!foundInFav && foundInTrack){
				cout << "Would you like to add this movie?";
				string confirmAdd;
				bool YorN = promptYesOrNo(confirmAdd);
				//reconfirm if they want to add, if yes, we add
				if (YorN){
					movie fMovie = user.ReturnTrackList().at(trackIndex);
					user.AddToFavoriteList(fMovie);
					//user.getFavoritesList().push_back(user.ReturnTrackList().at(i));
					
					cout << user.ReturnTrackList().at(trackIndex).getTitle() << " has been added to Favorites." << endl;
					++curSize;
				}
			}
			//if it is already in fav, we output message.
			else if (foundInFav){
				cout << "This movie is already in Favorites." << endl;
			}
			else if (!foundInTrack){
				cout << "Movie not found. Please enter a valid ItemId." << endl;
			}
			cout << "There are currently " << user.getFavoritesList().size() << " movies in your Favorites List." << endl;
			if (curSize < displaySize){
				cout << "Add a different movie? ";
				string u2Choice;
				bool u2ChoiceYorN = promptYesOrNo(u2Choice);
				//if so, we will rerun the addToFavorites() func.
				if (!u2ChoiceYorN){
					if (curSize > 1){
						cout << curSize << " movies have been added. ";	
					}
					else if (curSize == 1){
						cout << curSize << " movie has been added. ";
					}
					else {
						cout << "0" << " movies have been added. ";
					}
					
					break;	
				}	
			}
		}
		if (curSize == displaySize){
			cout << "All available movies have been added. Now returning." << endl;
		}
		else {
			cout << "Now returning to Previous Menu..." << endl;
		}
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

int Menu::countInFavorites(){
	int numInFav = 0;
	for (unsigned i = 0; i < user.getFavoritesList().size(); ++i){
		for (unsigned j = 0; j < user.ReturnTrackList().size(); ++j){
			if (user.getFavoritesList().at(i).getItemId() == user.ReturnTrackList().at(j).getItemId()){
				++numInFav;
			}
		}
	}
	return numInFav;
}

void Menu::printFavorites(){
	if (user.getFavoritesList().size() != 0){
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
		cout << endl;
		cout << "==================================================" << endl;
		cout << "Total of " << fav.size() << " movies in Favorites." << endl;
		cout << "==================================================" << endl;
	}
	else {
		cout << "There are no movies in the Favorites list." << endl;
	}
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

void Menu::getRecommendation(){

	optionTracker = 5;
	// vector<movie> recommendation = user.getRec();

	int userInput =1;
	int recSize = recommendation.size();
	while(userInput!=2){
		vector<movie> recommendation = user.getRec();
		user.ClearTrackList();
		unsigned randIndex;
		cout<<"\n\nHere are 5 movies you might like: "<<endl;
		for( unsigned i = 0 ; i < 5 ; i++){
			recSize = recommendation.size();
			randIndex = rand() % recSize;
			movie curMovie = recommendation.at(randIndex);
			// ViewingList.erase(ViewingList.begin() + idx);
			recommendation.erase(recommendation.begin() + randIndex);
			cout << i + 1 << "." << endl;
			curMovie.printMovie_2();
			//this tracks output movies
			user.AddToTrackList(recommendation.at(randIndex));
		}
		cout<<endl;
		// cout << "Test track size: " << user.ReturnTrackList().size() << endl;

		//since there is a sub menu after 
		cout << "Add any of the Movies to Favorites? ";
		string addChoice;
		bool YorN;
		// cout << "------------------" << endl;
		YorN = promptYesOrNo(addChoice);
		if (YorN){
			addToFavorites();
		}
		
		cout<<"1) Get more recommendations"<<endl;
		cout<<"2) Back to Menu"<<endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin>>userInput;

		while(userInput!=1 && userInput!=2){
			cout<< "Please choose"  <<endl;
			cout<< "1) Get more recommendations"<<endl;
			cout<< "2) Back to Menu. "<<endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin>>userInput;
		}


	}



}