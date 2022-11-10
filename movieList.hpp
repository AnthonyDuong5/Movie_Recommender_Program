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

	public:
		movieList();
		void readMovieListFiles();
		string parseStringFromCSV(const string &);
		void getCriteria();
		void sortList();
		//void sortByMovieTitle(string movieName);
			void sortAscendingTitles();
			void sortDescendingTitles();
		void sortByRating();
		void sortByGenre(string movieGenre);
				void sortByYear(int movieYear);		//initial function, changed to below function
		void sortAlphabetical();

		void sortByAscendingTitle();
		void sortByDescendingTitle();
		void sortBySpecificTitle(vector<movie>& movieList, char movieLetter);
		//local testing sortByYear function
		void sortYear(vector<movie>&);

		vector<movie>& returnList();
		vector<movie>& returnSortedList();
		void printMovies(const vector<movie>&);
};		


#endif