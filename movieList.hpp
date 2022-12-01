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
		vector <movie> latestTop30;
	public:

		//DEFAULT CONSTRUCTOR, CREATION OF MOVIE FILE, PARSING
		movieList();
		void readMovieListFiles();
		string parseStringFromCSV(const string &);

		//TITLE
		void sortAscendingTitles(vector <movie>&);
		void sortAscendingTitles_2(vector <movie>&);
		void sortDescendingTitles(vector <movie>&);
		void searchMovieTitle(string);
		vector<movie> searchMovieTitle(string, vector<movie>&);		//test

		//RATING
		void sortByRatingDescending();
		void sortByRatingAscending();
		void searchByRatings(double lowRating, double highRating);
		vector<movie> searchByRatings(double, double, vector<movie>&);
		void sortByRatingDescending_2( vector<movie>&);		//test

		//YEAR
		void sortByYearAscending();
		void sortByYearDescending();
		void searchYearRange(int, int);
		vector<movie> searchYearRange(int, int, vector<movie>&);
		vector<movie> searchYearRange_2(int, int, const vector<movie>&);		

		//GENRE
		void setGenres();
		vector <string> getGenres(); 
		void printGenres();
		vector<movie> searchByGenre(Genre);
		vector<movie> searchByGenre_2(Genre g, vector<movie>& filter);
		vector<movie> searchByGenre(int);
		vector<movie> searchByGenre(int, vector<movie>&);

		vector<movie> searchByDirector(string, const vector<movie> & filter);		//test

		//RETURN LIST/SORTEDLIST, PRINT MOVIE LIST
		vector<movie>& returnList();
		vector<movie>& returnSortedList();
		void printMovies();

		//FOR RECOMMENDATION
		vector <movie> returnLatestTop30(){return latestTop30;}
		void makeLatestTop30 (int);
		void mergeList(vector<movie>&m1,vector<movie>&m2,vector<movie>&m3);


};		

#endif