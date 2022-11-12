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
	fstream f("data/MovieDatabase.json");
    json moviedata = json::parse(f);

    int countMovies = 0;
	for (countMovies = 0; countMovies < moviedata.size(); ++countMovies){

		
		movie Movie1 (moviedata[countMovies]["title"], moviedata[countMovies]["directedBy"], 
					  moviedata[countMovies]["starring"], moviedata[countMovies]["avgRating"],
					  moviedata[countMovies]["imdbId"], moviedata[countMovies]["item_id"], moviedata[countMovies]["year"], moviedata[countMovies]["genresList"]);
		
		list.push_back(Movie1);
		
	
	}

	
    
}





//sorts movies by rating in descending order
void movieList::sortByRating() {
	sortedlist = list;
	int maxIdx;

	for (unsigned i = 0; i + 1 < sortedlist.size(); ++i) {
		maxIdx = i;

		for (unsigned j = i + 1; j < sortedlist.size(); ++j) {
			if (sortedlist.at(j).getRating() > sortedlist.at(maxIdx).getRating()) {
				maxIdx = j;
			}
		}

		swap(sortedlist.at(i), sortedlist.at(maxIdx));
	}
}

void movieList::printMovies(){
	vector<movie> movieListPrint = returnSortedList();
	for (int i =0; i < movieListPrint.size(); ++i){
		cout << "------------------" << endl;

		cout<<"title: "<< movieListPrint.at(i).getTitle()<<endl;
		cout<<"year: "<< movieListPrint.at(i).getYear()<<endl;
		cout<<"director: "<<movieListPrint.at(i).getDirector()<<endl;
		cout<<"casting: "<<movieListPrint.at(i).getCast()<<endl;
		cout<<"rating: "<<movieListPrint.at(i).getRating()<<endl;
		cout<<"IMDB ID: "<<movieListPrint.at(i).getImdbId()<<endl;
		cout<<"item: "<<movieListPrint.at(i).getItemId()<<endl;
		cout<<"Genre: "; for (auto gen : movieListPrint.at(i).getGenreList()){ cout<<gen<<" ";} cout<<endl;

	}
}

void movieList::sortByYearAscending() {
	sortedlist = list;
	int yearTop;
	for (int j = 0; j < sortedlist.size() - 1; ++j){
		int min = sortedlist.at(j).getYear();
		yearTop = j;
		for (int i = j+1; i < sortedlist.size(); ++i) {
			if (min > sortedlist.at(i).getYear()) {
				min = sortedlist.at(i).getYear();
				yearTop = i;
			}
		}
		std::swap(sortedlist.at(j), sortedlist.at(yearTop));
	}
}

void movieList::sortByYearDescending() {
	sortedlist = list;
	int yearLast;
	for (int j = 0; j < sortedlist.size() - 1; ++j){
		int max = sortedlist.at(j).getYear();
		yearLast = j;
		for (int i = j+1; i < sortedlist.size(); ++i) {
			if (max < sortedlist.at(i).getYear()) {
				max = sortedlist.at(i).getYear();
				yearLast = i;
			}
		}
		std::swap(sortedlist.at(j), sortedlist.at(yearLast));
	}
}

void movieList::selectYear(int yearInput) {
	sortedlist = list;
	vector<movie> newList;
	for (int i = 0; i < sortedlist.size() - 1; ++i){
		int movieYear = sortedlist.at(i).getYear();
		if(movieYear == yearInput) {
			newList.push_back(returnSortedList().at(i));
		}
	}
	sortedlist = newList;
}

// void movieList::sortByMovieTitle(string movieName) {

// }

void movieList::sortAscendingTitles(vector <movie>& l){
	sortedlist = l;
	int titleTop;
	for (unsigned i = 0; i < sortedlist.size(); ++i){
		titleTop = i;
		for (unsigned j = i + 1; j < sortedlist.size(); ++j){
			if (sortedlist.at(j).getTitle() < sortedlist.at(titleTop).getTitle() ){
				titleTop = j;
			}
		}
		swap (sortedlist.at(i), sortedlist.at(titleTop));
	}
}

void movieList::sortDescendingTitles(vector <movie>& l){
	sortedlist = l;
	int titleLast;
	for (unsigned i = 0; i < sortedlist.size(); ++i){
		titleLast = i;
		for (unsigned j = i + 1; j < sortedlist.size(); ++j){
			if (sortedlist.at(j).getTitle() > sortedlist.at(titleLast).getTitle() ){
				titleLast = j;
			}
		}
		swap (sortedlist.at(i), sortedlist.at(titleLast));
	}
}

void movieList::sortMovieByString(string m1){
	sortedlist = list;
	vector<movie> newList;
	string lowercasem1 = m1;
	string lowercasemsorted;
 
    // using transform() function and ::tolower in STL
    transform(lowercasem1.begin(), lowercasem1.end(), lowercasem1.begin(), ::tolower);
    cout<< "lowercase: " << lowercasem1<<endl;
 

	for (unsigned i = 0; i < sortedlist.size(); ++i){
		lowercasemsorted = sortedlist.at(i).getTitle();
		transform(lowercasemsorted.begin(), lowercasemsorted.end(), lowercasemsorted.begin(), ::tolower);
		if (lowercasemsorted.find(lowercasem1) != std::string::npos) {
    		//cout << "found!" << '\n';
			newList.push_back(returnSortedList().at(i));
		}
		
	}
	sortedlist = newList;
	//this is not sorted by alphabetical order, so we run sort ascending
	sortAscendingTitles(sortedlist);
}

 vector<movie>& movieList::returnList(){
	return list;
}

vector<movie>& movieList::returnSortedList() {
	return sortedlist;
}