#include "movie.hpp"
#include <string>

movie::movie(string title, string director, string cast, double rating, int imdbId, int itemId, int year, string genre)
:title(title),director(director),cast(cast),rating(rating),imdbId(imdbId),itemId(itemId),year(year), genre(genre)
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
string movie::getGenre() const {
	return genre;
}
void movie::getGenreList(){
	vector<string> genre_List;
	string delimiter = "|";
	size_t pos = 0;
	string s = genre;
	string item;
	while((pos=s.find(delimiter))!=string::npos){
		item = s.substr(0,pos);
		s.erase(0,pos+delimiter.length());
		genre_List.push_back(item);
	}      
	genre_List.push_back(s);
	genreList = genre_List;
}
vector<string> movie::return_genreList(){
	return genreList;
}
