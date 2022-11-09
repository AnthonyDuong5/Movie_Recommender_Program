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


void movieList::readMovieListFiles(){

	//read json file.
	fstream f("newdata3.json");
    json moviedata = json::parse(f);

    int countMovies = 0;
	for (countMovies = 0; countMovies < moviedata.size(); ++countMovies){

		if(moviedata[countMovies]["starring"]!=""&& moviedata[countMovies]["directedBy"]!=""&&moviedata[countMovies]["avgRating"]>=3.5){
		movie Movie1 (moviedata[countMovies]["title"], moviedata[countMovies]["directedBy"], 
					  moviedata[countMovies]["starring"], moviedata[countMovies]["avgRating"],
					  moviedata[countMovies]["imdbId"], moviedata[countMovies]["item_id"], moviedata[countMovies]["year"], moviedata[countMovies]["genres"]);
		
		list.push_back(Movie1);
		}
	}



}

// sorts movies by rating in descending order
void movieList::sortByRating() {
	int maxIdx;

	for (unsigned i = 0; i + 1 < list.size(); ++i) {
		maxIdx = i;

		for (unsigned j = i + 1; j < list.size(); ++j) {
			if (list.at(j).getRating() > list.at(maxIdx).getRating()) {
				maxIdx = j;
			}
		}

		swap(list.at(i), list.at(maxIdx));
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
