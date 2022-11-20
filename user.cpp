#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <stdio.h>  
#include <stdlib.h> 
#include <map>

#include "user.hpp"



User::User(){
	
	movieList MovieDatabase;
	MovieDatabase.readMovieListFiles();
	ViewingList = DefaultList = filteredList = MovieDatabase.returnList();
	UserName = "user1";		//we could ask the username later, doesn't matter much.
}

void User::removeFromViewingList(unsigned idx) {
	ViewingList.erase(ViewingList.begin() + idx);
}

void User::AddToFavoriteList(const movie& m1){
	Favorites.push_back(m1);
}

void User::AddToTrackList(const movie& m){
	TrackViewList.push_back(m);
}

void User::ClearTrackList(){
	TrackViewList.clear();
}

vector<movie> User::getRec(){
	vector<movie> rec;
	vector<int> yearlist;
	vector<string>directorlist;
	vector<Genre> genreslist;
	int favoriteCount = Favorites.size();



	//use criteria (year, director, director) to generate a rec list.
	//may be using different combination of criteria based on the condition
	int year1, year2, year3 =0;
	Genre gen1, gen2, gen3;
	string director1, director2, director3;
	vector <movie> filteredList1,filteredList2,filteredList3; //filter year, genre, string
   	int A, B, C = 0; //size of filteredList1, filteredList2, filteredList3

	//making a top 30 list
	MovieDatabase.makeLatestTop30(2018);
	vector<movie> latest30 = MovieDatabase.returnLatestTop30();
	//nothing in favorites, return top 30
	if(favoriteCount == 0){

		return rec = latest30;
	}
	
	//storing each critera (year, director, director) into its vector
	for(movie x: Favorites){ 
        yearlist.push_back(x.getYear());
		directorlist.push_back(x.getDirector());
		for(Genre y: x.genre_list){
			genreslist.push_back(y);
		}
	}

	//Check size of the favorites.
	//only one movie in favorites
	if(favoriteCount == 1){
		year1 = help_getTopFreq(yearlist);	
		gen1 = help_getTopFreq(genreslist);	
		director1 = help_getTopFreq(directorlist);	
	
		//Begin filtering
		filteredList1 = MovieDatabase.searchYearRange_2(year1, year1, filteredList);
		A = filteredList1.size();
		if (A!=0){

			filteredList2 = MovieDatabase.searchByGenre_2(gen1,filteredList1);
			B = filteredList2.size();
			
			if(B!=0){
				
				filteredList3 = MovieDatabase.searchByDirector(director1,filteredList);
				C = filteredList3.size();
			}
		
		}

		if(A<30){rec = filteredList1;}
   		else if(B<30){rec =filteredList2;}
   		else {rec = filteredList3;}


	}
	
	int recSize = rec.size();
	if(recSize<30){
		int j = 0;
		for(int i = recSize; i<30; i++){
			rec.push_back(latest30.at(j++));
		}
		
	}

	return rec;

}


