#include "movieList.hpp"
#include <string>
#include <vector>
#include "json/json.hpp"
#include "movie.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include <iostream>

using namespace std;
using json = nlohmann::json;

movieList::movieList(){}

void movieList::readMovieListFiles(){

	//read json file.
	fstream f("data/newdata.json");
    json moviedata = json::parse(f);

    int countMovies = 0;
	for (countMovies = 0; countMovies < moviedata.size(); ++countMovies){


		movie Movie1 (moviedata[countMovies]["title"], moviedata[countMovies]["directedBy"], 
					  moviedata[countMovies]["starring"], moviedata[countMovies]["avgRating"],
					  moviedata[countMovies]["imdbId"], moviedata[countMovies]["item_id"], moviedata[countMovies]["year"], moviedata[countMovies]["genres"]);
		
		list.push_back(Movie1);
	}

}

void movieList::printMovies(const vector<movie>& m){
	//temporarily changed m.size() to a fixed vector size
	for (int i =0; i < m.size(); ++i){
		cout << "------------------" << endl;
		cout<<"title: "<< m.at(i).getTitle()<<endl;
		cout<<"year: "<< m.at(i).getYear()<<endl;
		cout<<"director: "<<m.at(i).getDirector()<<endl;
		cout<<"casting: "<<m.at(i).getCast()<<endl;
		cout<<"rating: "<<m.at(i).getRating()<<endl;
		cout<<"IMDB ID: "<<m.at(i).getImdbId()<<endl;
		cout<<"item: "<<m.at(i).getItemId()<<endl;
		cout<<"Genre: "<<m.at(i).getGenre()<<endl;
	}
}

void movieList::sortYear(vector<movie>& newList) {

	//can try to replace newList.size() to a fixed number to see the first movies in the list
	//i've tried it and it seems to work in the lower end of the list as well
	//note: last movie has an incorrect year and is in the wrong spot because of it
	
	int temp;
	for (int j = 0; j < newList.size() - 1; ++j){
		int min = newList.at(j).getYear();
		temp = j;
		for (int i = j+1; i < newList.size(); ++i) {
			if (min > newList.at(i).getYear()) {
				min = newList.at(i).getYear();
				temp = i;
			}
		}
		std::swap(newList.at(j), newList.at(temp));
	}
	printMovies(newList);
}

void movieList::sortByMovieTitle(vector<movie>& movieList){
	//we use the sortedList vector to store the sorted movieList.
	//for this implementation, we are just fetching movies that start with a certain letter.
	cout << "Choose category to sort: "<< endl;
	cout << "1. Ascending (A-Z)" << endl;
	cout << "2. Descending (Z-A)" << endl;
	cout << "3. Search by Movie Name" << endl;
	int userSelection = 0;
	cin >> userSelection;
	while (userSelection == 0 || userSelection <0 || userSelection >3){
		cout << "Please enter a valid choice from 1 to 3.";
		cin >> userSelection;
	}
	
	if (userSelection == 1){
		sortByAscendingTitle();
	}
	else if (userSelection == 2){
		sortByDescendingTitle();
	}
	else {
		string movieName;
		cout << "Enter a movie name: " ;
		getline(cin, movieName);
		sortBySpecificTitle(movieList, movieName);
	}
	//sortBySpecificTitle(movieName);
	//if sortAscending

	//if sortDescending
}

void movieList::sortBySpecificTitle(vector<movie>& movieList, string movieName){
	for (int dbSize = 0; dbSize < movieList.size(); ++dbSize){

	}
}

void movieList::sortByAscendingTitle(){
	
}
void movieList::sortByDescendingTitle(){
	
}

 vector<movie>& movieList::returnList(){
	return list;
}

