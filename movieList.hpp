#ifndef __MOVIELIST_H__
#define  __MOVIELIST_H__
#include "movie.hpp"
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;


class movieList{
	private:
		vector <movie> list;
		vector <movie> sortedlist;
		vector <string> genres;

	public:
		movieList();
		void readMovieListFiles();
		string parseStringFromCSV(const string &);
		void getCriteria();
		void sortList();
		//void sortByMovieTitle(string movieName);
			void sortAscendingTitles(vector <movie>&);
			void sortDescendingTitles(vector <movie>&);
			void sortMovieByString(string );	//this finds all movies containing a specific string
		void sortByRatingDescending();
		void sortByRatingAscending();
		void searchByRatings(double lowRating, double highRating);
		void sortByGenre(string movieGenre);
				void sortByYear(int movieYear);		//initial function, changed to below function
		void sortAlphabetical();

		void sortBySpecificTitle(vector<movie>& movieList, char movieLetter);
		//local testing sortByYear function
		void sortYear(vector<movie>&);

		vector<movie>& returnList();
		vector<movie>& returnSortedList();
		void printMovies();
		vector <string> setGenres();

};		


#endif