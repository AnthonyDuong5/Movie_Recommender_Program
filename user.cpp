#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>  
#include <stdlib.h> 

#include "json/json.hpp"
#include "movie.hpp"
#include "movieList.hpp"
#include "user.hpp"

using namespace std;

User::User(){}

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

