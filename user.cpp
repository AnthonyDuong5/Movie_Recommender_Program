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
	
	vector<int> yearlist;
	vector<string>directorlist;
	vector<Genre> genreslist;
	int favoriteCount = Favorites.size();



	//use criteria (year, director, director) to generate a rec list.
	//may be using different combination of criteria based on the condition
	int year1, year2, year3 =0;
	Genre gen1, gen2, gen3;
	string director1, director2, director3;
	vector <movie> filteredList1,filteredList2,filteredList3,filteredList4 ; 
	vector <movie> rec, rec1, rec2, rec3, rec4;
   	int A, B, C, D = 0; //size of filteredList1, filteredList2, filteredList3, filteredList4

	map<Genre, int>freqGenre = help_getFreq(genreslist);

	//making a top 30 list
	MovieDatabase.makeLatestTop30(2018);

	vector<movie> latest30 = MovieDatabase.returnLatestTop30();
	//0: nothing in favorites
		//return top30 (for now)

	if(favoriteCount == 0){

		return latest30;
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
	//1: only one movie in favorites
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
				
				filteredList3 = MovieDatabase.searchByDirector(director1,filteredList2);
				C = filteredList3.size();
			}
		
		}

		if(A<30){rec = filteredList1;}
   		else if(B<30){rec =filteredList2;}
   		else {rec = filteredList3;}

		return rec;

	}

	//2. 2 movies in the favorites
	else if(favoriteCount == 2){

        //for 2 movies situation, take the union of 
		//{(year1, gen1, rate),(year1, gen2, rate),(year2, gen1, rate),(year2, gen2, rate)}
        //and select movies from it
        year1 = *min_element(yearlist.begin(),yearlist.end());
        year2 = *max_element(yearlist.begin(),yearlist.end());
        gen1 = help_getTopFreq(freqGenre);  

	//gen1 != gen2
		if(freqGenre.size()!=0){
        gen2 = help_getTopFreq(freqGenre);  
				
		
        //Begin filtering: year1 + gen1 + gen2 + high rate
			filteredList1 = MovieDatabase.searchYearRange_2(year1, year1, filteredList);
			A = filteredList1.size();
				
			//(year1 && gen1) 
			filteredList2 = MovieDatabase.searchByGenre_2(gen1,filteredList1);
			B = filteredList2.size();
			//(year1 && gen2)
			filteredList3 = MovieDatabase.searchByGenre_2(gen2,filteredList1);
			C = filteredList3.size();

			//(year1 && gen1) U (year1 && gen2)
			MovieDatabase.mergeList(filteredList2,filteredList3, filteredList4);
			D = filteredList4.size();
			if(D>10){
				MovieDatabase.sortByRatingDescending_2(filteredList4);
				for(int i = 0 ; i < 10 ; i ++){
					rec1.push_back(filteredList4.at(i));
				}
			}
			else {
				rec1 = filteredList4;
			}
				
			if(year1!=year2){
			//filtering: year2 + gen1 + gen2 + high rate		
				filteredList1 = MovieDatabase.searchYearRange_2(year2, year2, filteredList);
				A = filteredList1.size();
					
				//(year2 && gen1) 
				filteredList2 = MovieDatabase.searchByGenre_2(gen2,filteredList1);
				B = filteredList2.size();
				//(year2 && gen2)
				filteredList3 = MovieDatabase.searchByGenre_2(gen2,filteredList1);
				C = filteredList3.size();

				//(year2 && gen1) U (year2 && gen2)
				MovieDatabase.mergeList(filteredList2,filteredList3, filteredList4);
				D = filteredList4.size();
				if(D>10){
					MovieDatabase.sortByRatingDescending_2(filteredList4);
					for(int i = 0 ; i < 10 ; i ++){
						rec2.push_back(filteredList4.at(i));
					}
				}
				else {
					rec2 = filteredList4;
				}
				MovieDatabase.mergeList(rec1, rec2, rec3);


				rec = rec3;
			}
			else{
				rec = rec1;
			}
		}

	//gen1 == gen2
		else{
	
        //Begin filtering: year1 + gen1 + high rate
			filteredList1 = MovieDatabase.searchYearRange_2(year1, year1, filteredList);
			A = filteredList1.size();
				
			//(year1 && gen1) 
			filteredList2 = MovieDatabase.searchByGenre_2(gen1,filteredList1);
			B = filteredList2.size();

			if(B>10){
				MovieDatabase.sortByRatingDescending_2(filteredList2);
				for(int i = 0 ; i < 10 ; i ++){
					rec1.push_back(filteredList2.at(i));
				}
			}
			else {

				rec1 = filteredList2;
			}
				
			if(year1!=year2){
			//filtering: year2 + gen1 + high rate		
				filteredList1 = MovieDatabase.searchYearRange_2(year2, year2, filteredList);
				A = filteredList1.size();
					
				//(year2 && gen1) 
				filteredList2 = MovieDatabase.searchByGenre_2(gen2,filteredList1);
				B = filteredList2.size();

				if(B>10){
					MovieDatabase.sortByRatingDescending_2(filteredList2);
					for(int i = 0 ; i < 10 ; i ++){
						rec2.push_back(filteredList2.at(i));
					}
				}
				else {
					rec2 = filteredList2;
				}
				MovieDatabase.mergeList(rec1, rec2, rec3);
				rec = rec3;
			}

			else{

				rec = rec1;
			}

		}

    }

		
	

	//3. 3+ movies in the favorites
		// using year range and genre1, genre2, genre3
	else if (favoriteCount>=3){

	



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


