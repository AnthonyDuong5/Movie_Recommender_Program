#include "movieList.hpp"
#include <string>
#include <vector>
#include "json/json.hpp"
#include "movie.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
using json = nlohmann::json;

movieList::movieList(){}

//reads each string and parses through each row to get genre
string movieList::parseStringFromCSV(const string &movieString){
	int commaCount = 0;
	bool checkQuotes = false;
	int QuoteCount = 0;
	char curChar;
	string movie = movieString;
	string GenrePrint = "";
	//each string has "movieID,title,genres"
	//the title can contain , as well, and for those, we have to skip
	for (int i =0; i < movie.length()-1; ++i){
		if (movie.at(i) == '"'){
			checkQuotes == true;
			++QuoteCount;
		}
		if (movie.at(i) == ',' && checkQuotes == false && (QuoteCount == 0 || QuoteCount == 2)){
			++commaCount;
		}
		if (commaCount == 2){
			curChar = movie.at(i+1);
			GenrePrint += curChar;
		}
	}
	return GenrePrint;
}


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
	for (int i =0; i < m.size(); ++i){
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
vector<movie> movieList::returnList(){
	return list;
}
