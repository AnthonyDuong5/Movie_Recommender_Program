#include "movie.hpp"
#include <string>


movie::movie(string title, string director, string cast, double rating, int imdbId, int itemId, int year, vector<string> genre)
:title(title),director(director),cast(cast),rating(rating),imdbId(imdbId),itemId(itemId),year(year), genreList(genre)
{}

string movie::getTitle() const {
	return title;
}

int movie::getYear() const {
	return year;
}

string movie::getDirector() const {
	return director;
}

string movie::getCast() const {
	return cast;
}

double movie::getRating() const {
	return rating;
}

int movie::getImdbId() const {
	return imdbId;
}

int movie::getItemId() const {
	return itemId;
}

vector<string> movie::getGenreList() const{
	return genreList;
}

void movie::printMovie(){

		cout << "--------------------------------------------------" << endl;
		cout << "itemID: " << itemId << endl;
		cout << "title: " << title << endl;
		//cout << "year: " << year<< endl;
		cout << "director: " << director << endl;
		cout << "casting: " << cast << endl;
		cout << "rating: " << rating << endl;
		//cout << "imbdid: " << imdbId<< endl;
		cout << "genre: ";
		for (string x : genreList) {cout << x << " ";} 
		cout << endl;
		cout << "--------------------------------------------------" << endl;
	
}

void movie::printMovie_2(){

		cout << "--------------------------------------------------" << endl;
		cout << "itemID: " << itemId << endl;
		cout << "title: " << title << endl;
		//cout << "year: " << year<< endl;
		cout << "director: " << director << endl;
		//cout << "casting: " << cast << endl;
		//cout << "rating: " << rating << endl;
		//cout << "imbdid: " << imdbId<< endl;
		cout << "genre: ";
		for (string x : genreList) {cout << x << " ";} 
		cout << endl;
		cout << "--------------------------------------------------" << endl;
	
}
