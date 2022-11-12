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
	
		void sortAscendingTitles(vector <movie>&);
		void sortDescendingTitles(vector <movie>&);
		void sortMovieByString(string );	
		void sortByRating();
		void sortByGenre(string movieGenre);
				void sortByYear(int movieYear);		//initial function, changed to below function
		void sortAlphabetical();

		void sortBySpecificTitle(vector<movie>& movieList, char movieLetter);
		//local testing sortByYear function
		void sortYear(vector<movie>&);

		vector<movie>& returnList();
		vector<movie>& returnSortedList();
		void printMovies();

			void setGenres();
			vector <string> getGenres();
			void printGenres();
			vector<movie> searchByGenre(Genre);

		

};		


#endif