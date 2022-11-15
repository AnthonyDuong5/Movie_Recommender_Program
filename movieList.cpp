#include "movieList.hpp"
#include "json/json.hpp"
#include "movie.hpp"
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <iostream>
#include <algorithm>

#define find_str( a, b ) std::find( a.begin(), a.end(), b ) == a.end() 

using namespace std;
using json = nlohmann::json;

movieList::movieList(){}


Genre HashIt (std::string const& inString) {
	//C++ does not support string as a type, so convert string to Genre here.	
	//Genre g = "Adventure" does not work.
	//Solution : Genre g = HashIt("Adventure")
    if (inString == "Adventure") return Adventure;
	else if (inString == "Action") return Action;
	else if (inString == "Animation") return Animation;
	else if (inString == "Children") return Children;
	else if (inString == "Comedy") return Comedy;	
	else if (inString == "Crime") return Crime;
	else if (inString == "Documentarys") return Documentarys;
	else if (inString == "Drama") return Drama;
	else if (inString == "Fantasy") return Fantasy;
	else if (inString == "Film-Noir") return FilmNoir;
	else if (inString == "Horror") return Horror;
	else if (inString == "IMAX") return IMAX;
	else if (inString == "Musical") return Musical;
	else if (inString == "Mystery") return Mystery;
	else if (inString == "Romance") return Romance;	
	else if (inString == "Sci-Fi") return SciFi;
	else if (inString == "Thriller") return Thriller;
	else if (inString == "War") return War;
	else if(inString == "Western") return Western;
	return Comedy;
}

void movieList::readMovieListFiles(){

	//read json file.
	fstream f("data/MovieDatabase.json");
    json moviedata = json::parse(f);

    int countMovies = 0;
	for (countMovies = 0; countMovies < moviedata.size(); ++countMovies){
		
		
		movie Movie1 (moviedata[countMovies]["title"], moviedata[countMovies]["directedBy"], 
					  moviedata[countMovies]["starring"], moviedata[countMovies]["avgRating"],
					  moviedata[countMovies]["imdbId"], moviedata[countMovies]["item_id"], moviedata[countMovies]["year"], moviedata[countMovies]["genresList"]);
		
		//store genres to vector<Genre>genre_list
		for(int i = 0 ; i < moviedata[countMovies]["genresList"].size();i++){
			string g = moviedata[countMovies]["genresList"][i];
			Movie1.genre_list.push_back(HashIt(g));
		}
		list.push_back(Movie1);
	
	}
	//read Genres.txt from local and stores 19 genres into genres in movieList's member vector<string> genres. 
	setGenres();
	
}





//sorts movies by rating in descending order
void movieList::sortByRatingDescending() {
	sortedlist = list;
	unsigned maxIdx;

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

//sorts movies by rating in ascending order
void movieList::sortByRatingAscending() {
	sortedlist = list;
	unsigned minIdx;

	for (unsigned i = 0; i + 1 < sortedlist.size(); ++i) {
		minIdx = i;

		for (unsigned j = i + 1; j < sortedlist.size(); ++j) {
			if (sortedlist.at(j).getRating() < sortedlist.at(minIdx).getRating()) {
				minIdx = j;
			}
		}

		swap(sortedlist.at(i), sortedlist.at(minIdx));
	}
}

//searches movies from a range of ratings
void movieList::searchByRatings(double lowRating, double highRating) {
	sortByRatingAscending();
	vector<movie> searchList;

	for (unsigned i = 0; i < sortedlist.size(); ++i) {
		if (sortedlist.at(i).getRating() >= lowRating && sortedlist.at(i).getRating() <= highRating) {
			searchList.push_back(sortedlist.at(i));
		}
	}

	sortedlist = searchList;
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

void movieList::searchYearRange(int minYear, int maxYear) {
	sortByYearAscending();
	vector<movie> newList;
	for (int i = 0; i < sortedlist.size() - 1; ++i){
		int currentYear = sortedlist.at(i).getYear();
		if(currentYear >= minYear && currentYear <= maxYear) {
			newList.push_back(sortedlist.at(i));
		}
	}
	sortedlist = newList;
}

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

void movieList::searchMovieTitle(string m1){
	sortedlist = list;
	vector<movie> newList;
	string lowercasem1 = m1;
	string lowercasemsorted;
 
    // using transform() function and ::tolower in STL
    transform(lowercasem1.begin(), lowercasem1.end(), lowercasem1.begin(), ::tolower);
    // cout<< "lowercase: " << lowercasem1<<endl;
 

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



void movieList::setGenres(){

	ifstream in( "data/Genres.txt" );
	string genre;
	while( getline( in, genre) ){
		genres.push_back(genre);
	}

};
vector<string> movieList::getGenres(){
	     
	return genres;
}

void movieList::printGenres(){
	//list 19 genres from MovieDatabase
	for (int i = 0 ; i < genres.size(); i++){
		cout<<i+1<<". "<<genres.at(i)<<endl;
	}
	
}

vector<movie> movieList::searchByGenre(Genre g){

	vector<movie> newlist;
	
	for (int i = 0; i< list.size();i++){
		vector <Genre> gen_list = list.at(i).genre_list;
		for (auto x : gen_list){
			if(x==g){
				newlist.push_back(list.at(i));
				break;
			}
		}
	}
	
	return newlist;
}

vector<movie> movieList::searchByGenre(int userInput ){

	vector<movie> newlist;
	string gType = genres.at(userInput-1);
	Genre g = HashIt(gType);
	
	for (int i = 0; i< list.size();i++){
		vector <Genre> gen_list = list.at(i).genre_list;
		for (auto x : gen_list){
			if(x==g){
				newlist.push_back(list.at(i));
				break;
			}
		}
	}

	return newlist;
}
	

