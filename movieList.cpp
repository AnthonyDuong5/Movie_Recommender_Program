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

string movieList:: parseGenrefromJson(int item_id, json & data2){
    string genra = "";
    for (int i = 0; i < data2.size(); i++){
        if (data2[i]["movieId"]==item_id){
            genra =  data2[i]["genres"];
            data2.erase(i);
        }
    }
    return genra;
};
void movieList::readMovieListFiles(){
	//we create vector of strings that solely store genre.
	// ifstream movieGenre;
	// movieGenre.open("data/movies.csv");
	// if (!movieGenre.is_open()){
	// 	cout << "File not open" << endl;
	// }
	// vector <string> Movies;
	// int counter = 0;
	// string line;

	// while (getline (movieGenre, line, '\n')){
	// 	//reads the text until we get to the comma, then stop and store that into the variable called line
	// 	Movies.push_back(line);
	// 	++counter;
	// }
	//parse strings in vector
	// string movieString, genreString = "";
	// vector <string> genre;
	// for (int i = 1; i < Movies.size(); ++i){
	// 	movieString = Movies.at(i);
	// 	genre.push_back(parseStringFromCSV(movieString));		//calls parseString function
	// }
	
	
	//read json file.
	fstream f("data/metadata_updated.json");
	fstream csvf("data/csvjson.json");
    json moviedata = json::parse(f);
	json data2 = json::parse(csvf);

    int countMovies = 0;
	for (countMovies = 0; countMovies < 62423; ++countMovies){
		string tempMovieInfo = moviedata[countMovies]["imdbId"];
		int imdb = atoi(tempMovieInfo.c_str());								//converts string to int
		
		int movieYear = 0;
		string title = moviedata[countMovies]["title"];
		for(int i = 0; i < title.size(); i++){
			if(title.at(i)=='('&& (title.at(i+1)=='1'||title.at(i+1)=='2')){
				movieYear = (int(title.at(i+1))-48)*1000 + (int(title.at(i+2))-48)*100  +
							(int(title.at(i+3))-48)*10   + (int(title.at(i+4))-48); 
				
				break;
			}
        	else (movieYear = 0);
		}

		string genre = parseGenrefromJson(moviedata[countMovies]["item_id"],data2);
		//review this construction.
		movie Movie1 (moviedata[countMovies]["title"], moviedata[countMovies]["directedBy"], 
					  moviedata[countMovies]["starring"], moviedata[countMovies]["avgRating"],
					  imdb, moviedata[countMovies]["item_id"], movieYear, genre);
		
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
