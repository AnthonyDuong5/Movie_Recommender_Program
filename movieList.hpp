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
		vector <string> genres;  //stores 19 genres 
		
	public:

		//DEFAULT CONSTRUCTOR, CREATION OF MOVIE FILE, PARSING
		movieList();
		void readMovieListFiles();
		string parseStringFromCSV(const string &);

		//TITLE
		void sortAscendingTitles(vector <movie>&);
		void sortDescendingTitles(vector <movie>&);
		void sortMovieByString(string );

		//RATING
		void sortByRatingDescending();
		void sortByRatingAscending();
		void searchByRatings(double lowRating, double highRating);

		//YEAR
		void sortByYearAscending();
		void sortByYearDescending();
		void searchYearRange(int, int);		// <- just modfied on 11-12-22

		//GENRE
		void setGenres();
		vector <string> getGenres(); 
		void printGenres();
		vector<movie> searchByGenre(Genre);
		vector<movie> searchByGenre(int);

		//RETURN LIST/SORTEDLIST, PRINT MOVIE LIST
		vector<movie>& returnList();
		vector<movie>& returnSortedList();
		void printMovies();

// ------------------------- Incomplete/Pending Function Progress------------------- //


	//unfinished functions or functions that can be removed if not needed
	void sortBySpecificTitle(vector<movie>& movieList, char movieLetter);
	void sortAlphabetical();
	void getCriteria();
	void sortList();
		
};		

#endif