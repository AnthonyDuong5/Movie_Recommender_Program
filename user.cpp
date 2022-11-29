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
	int year1, year2;
	Genre gen1, gen2, gen3;
	string director1;
	vector <movie> filteredList1,filteredList2,filteredList3,filteredList4,filteredList5 ; 
	vector <movie> rec, rec1, rec2, rec3, rec4;
   	int A, B, C, D, E = 0; //size of filteredList1, filteredList2, filteredList3, filteredList4, filteredList5

	//making a top 30 list
	int latestYear = 2018;
	MovieDatabase.makeLatestTop30(latestYear);
	vector<movie> latest30 = MovieDatabase.returnLatestTop30();
	
	//adding up to 5 movies from the TrackViewList to rec. Based on most seen genre
	if(TrackViewList.size()!=0){ 
		vector<Genre> genreslist1;

		for(movie x: TrackViewList){ 
			for(Genre y: x.genre_list){
				genreslist1.push_back(y);
			}
		}

		map<Genre, int>freqGenre1 = help_getFreq(genreslist1);
		gen1 = help_getTopFreq(genreslist1);
		rec1 = MovieDatabase.searchByGenre(gen1,TrackViewList);
		MovieDatabase.sortByRatingDescending_2(rec1);
		
		if(rec1.size()==1){
			rec.push_back(rec1.at(0));}
		if(rec1.size()==2){
			rec.push_back(rec1.at(0));
			rec.push_back(rec1.at(1));}
		if(rec1.size()==3){
			rec.push_back(rec1.at(0));
			rec.push_back(rec1.at(1));
			rec.push_back(rec1.at(2));}
		if(rec1.size()==4){
			rec.push_back(rec1.at(0));
			rec.push_back(rec1.at(1));
			rec.push_back(rec1.at(2));
			rec.push_back(rec1.at(3));}
		if (rec1.size()>=5){
			rec.push_back(rec1.at(0));
			rec.push_back(rec1.at(1));
			rec.push_back(rec1.at(2));
			rec.push_back(rec1.at(3));
			rec.push_back(rec1.at(4));
		}
		
	}
	

	//0: nothing in favorites, get rec from viewdList recommendation and latestTop30
	if(favoriteCount == 0){
	
		int recSize = rec.size();
		int j = 0;
		for(int i = recSize; i<30; i++){
			rec.push_back(latest30.at(j++));
		}

		return rec;
	}
	
	//storing each critera (year, director, director) into its vector
	for(movie x: Favorites){ 
        yearlist.push_back(x.getYear());
		directorlist.push_back(x.getDirector());
		for(Genre y: x.genre_list){
			genreslist.push_back(y);
		}
	}
	//get the frequency map of genre
	map<Genre, int>freqGenre = help_getFreq(genreslist);

	//Check size of the favorites.
	//1: only 1 movie in favorites
	
	if(favoriteCount == 1){
		cout << "WE ARE HERE" << endl;
		cout << "WE ARE HERE" << endl;
		year1 = help_getTopFreq(yearlist);	
		gen1 = help_getTopFreq(genreslist);	
		director1 = help_getTopFreq(directorlist);	
		cout<<year1<<"||" << gen1<< "||" << director1 << endl;
	
		//Begin filtering
		filteredList1 = MovieDatabase.searchYearRange_2(year1, year1, filteredList);
		A = filteredList1.size();
		//check size of filtered list1.
		if (A!=0){

			filteredList2 = MovieDatabase.searchByGenre_2(gen1,filteredList1);
			B = filteredList2.size();
			// check size of filtered list 2
			if(B!=0){
				
				filteredList3 = MovieDatabase.searchByDirector(director1,filteredList2);
				C = filteredList3.size();
			}
		
		}
		if(A<30){
			rec = filteredList1; 
			cout << "WE ASSIGNED REC in IF" << endl;
		}
   		else if(B<30){
			rec =filteredList2;
			cout << "WE ASSIGNED REC in ELSE IF" << endl;
		}
   		else {
			rec = filteredList3;
			cout << "WE ASSIGNED REC in ELSE" << endl;
		}
		cout << "REC SIZE IS: " << rec.size() << endl;
		vector <movie> dupCheckList = rec;
		bool checkDupe = false;
		for (int i = 0; i < rec.size(); ++i){
			for (int j = i+1; j < dupCheckList.size()-1; ++j){
				if (dupCheckList.at(j).getItemId() == rec.at(i).getItemId()){
					checkDupe = true;
					cout << "DUPLICATE IS FOUND" << endl;
					dupCheckList.at(j).printMovie();
					cout << "THIS IS THE DUPLICATE" << endl;
					break;
				}
			}
		}
	}

	//2. 2 movies in the favorites
	else if(favoriteCount == 2){
		cout << "ENTERED favoriteCount == 2" << endl;
        //for 2 movies situation, take the union of 
		//{(year1, gen1, rate),(year1, gen2, rate),(year2, gen1, rate),(year2, gen2, rate)}
        //and select movies from it
        year1 = *min_element(yearlist.begin(),yearlist.end());
        year2 = *max_element(yearlist.begin(),yearlist.end());
        gen1 = help_getTopFreq(freqGenre);  
		

	//gen1 != gen2
		if(freqGenre.size()!=0){
			cout << "Entered freqGenre.size() != 0" << endl;
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
				cout << "Entered D> 10" << endl;
				MovieDatabase.sortByRatingDescending_2(filteredList4);
				for(int i = 0 ; i < 10 ; i ++){

					rec1.push_back(filteredList4.at(i));
				}
			}
			else {
				cout << "Entered freqGenre.size() != 0 >> else" << endl;
				rec1 = filteredList4;
			}
				
			if(year1!=year2){
			//filtering: year2 + gen1 + gen2 + high rate		
				cout << "Entered year1 != year2" << endl;
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
					cout << "year1 != year2 >>> else" << endl;
					rec2 = filteredList4;
				}
				MovieDatabase.mergeList(rec1, rec2, rec3);

				rec = rec3;

			}
			else{
				cout << "Entered else (year1 == year2)" << endl;
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
	else {
		//use: (year range, genre1, genre2, genre3)
		year1 = *min_element(yearlist.begin(),yearlist.end());
        year2 = *max_element(yearlist.begin(),yearlist.end());
		director1 = help_getTopFreq(directorlist);	
		
		
		//only 1 genre in favorites, use: (gen1, director1)
		if(freqGenre.size()==1){ 
			gen1 = help_getTopFreq(freqGenre);
			//filter (year range, gen1)
			filteredList1 = MovieDatabase.searchYearRange_2(year1, year2, filteredList);
			filteredList2 = MovieDatabase.searchByGenre_2(gen1,filteredList1);
			B = filteredList2.size();
			//(year range + gen1 <= 10) 
			if(B<=10){rec1 = filteredList2;}
			
			else {
				//(year range + gen1 >10) , add director filter
				filteredList3 = MovieDatabase.searchByDirector(director1,filteredList2);
				C = filteredList3.size();
				if(C!= 0){
					if(C==1) {
						rec1.push_back(filteredList3.at(0));
						MovieDatabase.sortByRatingDescending_2(filteredList2);
							for(int i = 0 ; i < 9 ; i ++){
							//rec1 = (year range + gen1 + 1 movies from director1 )
							rec1.push_back(filteredList2.at(i));
						}
					}
					if(C==2) {
						rec1.push_back(filteredList3.at(0));
						rec1.push_back(filteredList3.at(1));
						MovieDatabase.sortByRatingDescending_2(filteredList2);
							for(int i = 0 ; i < 8 ; i ++){
							//rec1 = (year range + gen1 + 2 movies form director1 )
							rec1.push_back(filteredList2.at(i));
						}
					}
				}
				MovieDatabase.sortByRatingDescending_2(filteredList2);
					for(int i = 0 ; i < 20 ; i ++){
						//rec1 = (year range + gen1)
						rec1.push_back(filteredList2.at(i));
					}
			}

			rec = rec1;	
		}
		// 2 genres in favorites, use: gen1, gen2
		else if(freqGenre.size()==2){
			gen1 = help_getTopFreq(freqGenre); 
			gen2 = help_getTopFreq(freqGenre); 

			//(year range)
			filteredList1 = MovieDatabase.searchYearRange_2(year1, year2, filteredList);

			//(range && gen1)
			filteredList2 = MovieDatabase.searchByGenre_2(gen1,filteredList1);

			//(range && gen2)
			filteredList3 = MovieDatabase.searchByGenre_2(gen2,filteredList1);
			
			//(range && gen1) U (range && gen2)
			MovieDatabase.mergeList(filteredList2,filteredList3, filteredList4);

					D = filteredList4.size();
					
					if(D>20){
						MovieDatabase.sortByRatingDescending_2(filteredList4);
						for(int i = 0 ; i < 20 ; i ++){

							rec.push_back(filteredList4.at(i));
						}
					}
					else {

						rec = filteredList4;
					}

		}
		// more than 3 genres in favorites, use: gen1 gen2 gen 3
		else{
			gen1 = help_getTopFreq(freqGenre); 
			gen2 = help_getTopFreq(freqGenre); 
			gen3 = help_getTopFreq(freqGenre); 

			//(year range)
			filteredList1 = MovieDatabase.searchYearRange_2(year1, year2, filteredList);
			//(range && gen1)
			filteredList2 = MovieDatabase.searchByGenre_2(gen1,filteredList1);
			
			//(range && gen2)
			filteredList3 = MovieDatabase.searchByGenre_2(gen2,filteredList1);
			
			//(range && gen3)
			filteredList4 = MovieDatabase.searchByGenre_2(gen3,filteredList1);
			
			//merge 3 filteredlists
			MovieDatabase.mergeList(filteredList2,filteredList3, filteredList1);
			MovieDatabase.mergeList(filteredList1,filteredList4, filteredList5);

					E = filteredList5.size();					
					if(E>20){
						MovieDatabase.sortByRatingDescending_2(filteredList4);
						for(int i = 0 ; i < 20 ; i ++){

							rec.push_back(filteredList4.at(i));
						}
					}
					else {

						rec = filteredList4;
					}		

		}
	}
	


	int recSize = rec.size();
	if(recSize<30){
		int j = 0;
		for(int i = recSize; i<30; i++){
			rec.push_back(latest30.at(j++));
		}
		
	}

	

	cout << "Rec size: " << rec.size() << endl;
	for (unsigned i = 0; i < rec.size(); ++i){
		cout << rec.at(i).getTitle() << endl;
	}
	return rec;
	
}



