#include "movie.hpp"
#include <string>

movie::movie(string title, string director, string cast, double rating, int imdbId, int itemId, int year, string Genre)
:title(title),director(director),cast(cast),rating(rating),imdbId(imdbId),itemId(itemId),year(year), Genre(Genre)
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
	return Genre;
}
