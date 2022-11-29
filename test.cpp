#include "movie.hpp"
#include "movieList.hpp"
#include "user.hpp"
#include "menu.hpp"
#include "gtest/gtest.h"
#include <vector>
#include <cstdlib>

// TEST(VectorTest, testException) {
//     EXPECT_NO_THROW({
//         vector<movie> movieList;
//     });
// }


// TEST(SortTest, testSortByRatingDescending) {
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.sortByRatingDescending();
//     for (unsigned i = 0; i < 5000; i+=500) {
//         MovieDatabase.returnSortedList().at(i).printMovie();
// 	}
// }

// TEST(SortTest, testSortByRatingAscending) {
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.sortByRatingAscending();
//     for (unsigned i = 0; i < 5000; i+=500) {
//         MovieDatabase.returnSortedList().at(i).printMovie();
// 	}
// }

TEST(SortTest, testSortAscendingYear) {
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.sortByYearAscending();
	for (unsigned i = 1; i < MovieDatabase.returnSortedList().size(); ++i) {
		if (MovieDatabase.returnSortedList().at(i).getYear() < MovieDatabase.returnSortedList().at(i - 1).getYear()) {
			FAIL() << "Movies are not correctly sorted by year in ascending order.";
		}
	}
	SUCCEED() << "Movies are correctly sorted by year in ascending order.";
}

TEST(SortTest, testSortDescendingYear) {
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.sortByYearDescending();
    for (unsigned i = 1; i < MovieDatabase.returnSortedList().size(); ++i) {
        if (MovieDatabase.returnSortedList().at(i).getYear() > MovieDatabase.returnSortedList().at(i - 1).getYear()) {
			FAIL() << "Movies are not correctly sorted by year in descending order.";
		}
	}
	SUCCEED() << "Movies are correctly sorted by year in descending order.";
}

TEST(SortTest, testSearchByYear) {
    movieList MovieDatabase;
	int minYear = 2000;
	int maxYear = 2002;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.searchYearRange(minYear, maxYear);
    for (unsigned i = 1; i < MovieDatabase.returnSortedList().size(); ++i) {
        if (MovieDatabase.returnSortedList().at(i).getYear() < MovieDatabase.returnSortedList().at(i - 1).getYear()) {
			FAIL() << "Movies are not correctly sorted by year in ascending order.";
		}
	}
	for (unsigned i = 0; i < MovieDatabase.returnSortedList().size(); ++i) {
		if (MovieDatabase.returnSortedList().at(i).getYear() < minYear || MovieDatabase.returnSortedList().at(i).getYear() > maxYear) {
			FAIL() << "Movies are not correctly filtered by year within the search range.";
		}
	}
	SUCCEED() << "Movies are correctly filtered by year within the search range and sorted by year in ascending order.";
}


// TEST(SortTest, testSearchByRatings) {
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.searchByRatings(4.0, 4.5);
//     for (unsigned i = 100; i < 1100; i += 100) {
//         MovieDatabase.returnSortedList().at(i).printMovie();
// 	}
// }

// TEST(SortTest, testSortAscendingTitles) {
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.sortAscendingTitles(MovieDatabase.returnList());
// 	for (unsigned i = 0; i < 5000; i+=500) {
//         MovieDatabase.returnSortedList().at(i).printMovie();
// 	}
// }

// TEST(SortTest, testSortDescendingTitles) {
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.sortDescendingTitles(MovieDatabase.returnList());
//     for (unsigned i = 0; i < 5000; i+=500) {
//         MovieDatabase.returnSortedList().at(i).printMovie();
// 	}
// }


// TEST (SortTest, testSearchMovieTitle){
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.searchMovieTitle("Hotel");
//     for (unsigned i = 0; i < MovieDatabase.returnSortedList().size(); ++i) {
//         MovieDatabase.returnSortedList().at(i).printMovie();
// 	}
// }


// TEST(SortByGenres, testGenreList){
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     cout << "database has been set, print genres" << endl;
//     MovieDatabase.printGenres();
//     cout << "finish printing genres."<<endl;

//     EXPECT_EQ(MovieDatabase.getGenres().size(),19);
// }

// TEST(SortByGenres, searchByGenre_Genre){
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     cout << "database has been set" << endl;
//     Genre gType = Mystery; 
//     vector<movie> genreMovieList = MovieDatabase.searchByGenre(gType);
//     cout << genreMovieList.size()<< " movies from Mystery."<<endl;
//     for (unsigned i = 0; i < 10; i ++) {
//         genreMovieList.at(i).printMovie();
//     }
// }

// TEST(SortByGenres, searchByGenre_int){
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     cout << "database has been set" << endl;
//     int input = 1; 
//     vector<movie> genreMovieList = MovieDatabase.searchByGenre(input);
//     cout << genreMovieList.size()<< " movies from Adventure."<<endl;
//     for (unsigned i = 0; i < 10; i ++) {
//         genreMovieList.at(i).printMovie();
//     }
// }

// TEST(movie, printmovie){
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     vector<movie> MovieList = MovieDatabase.returnList();
//     for (movie x: MovieList){
//         x.printMovie();
//     }
//     cout<<MovieList.size()<<" movies"<<endl;
// }

// TEST(getRec, yearFrequence){
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     vector<movie> MovieList = MovieDatabase.returnList();
//     //get all the years of Database and calculate its frequency
//     vector<int>yearlist;
//     for(auto x: MovieList){
//         yearlist.push_back(x.getYear());
//     }
//     //using a map to store year:frequency
//     map<int, int> freqMap;
// 	for( int x : yearlist){
// 		if(freqMap.find(x)==freqMap.end()){
// 			freqMap[x]=1;
// 		}
// 		else{
// 			freqMap[x]++;
// 		}
// 	}
	
// 	for (auto& it : freqMap) {
//         cout << it.first << ' '
//              << it.second << endl;
//     }
//     cout << help_getMaximumValue(freqMap).first<<endl;
// }


// TEST(getRec, yearFrequence_template){

//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     vector<movie> MovieList = MovieDatabase.returnList();
//     //get all the years of Database and calculate its frequency
//     vector<int>yearlist;
//     for(auto x: MovieList){
//         yearlist.push_back(x.getYear());
//     }
//     //using a map to store year:frequency
//     map<int, int> freqMap = help_getFreq(yearlist);
//     cout << "#1 year: "<<help_getMaximumValue(freqMap).first<<" "<<help_getMaximumValue(freqMap).second<<endl;
// }


// TEST(getRec, directorFrequence_template){
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     vector<movie> MovieList = MovieDatabase.returnList();
//     vector<string>dir;
//     for(auto x: MovieList){
//         dir.push_back(x.getDirector());
//     }
    
//     map<string, int> freqMap = help_getFreq(dir);
//     // 	for (auto& it : freqMap) {
//     //      cout << it.first << ' '
//     //           << it.second << endl;
//     //  }
//     cout << "#1 director: "<<help_getMaximumValue(freqMap).first<<" "<<help_getMaximumValue(freqMap).second<<endl;
// }

// TEST(getRec, genreFrequence_template){
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     vector<movie> MovieList = MovieDatabase.returnList();
//     //get all the years of Database and calculate its frequency
//     vector<Genre> genres;
// 	for (auto x: MovieList){
// 		for(auto y: x.genre_list){
// 			genres.push_back(y);
// 		}
// 	}
//     map<Genre, int> freqMap3 = help_getFreq(genres);	
// 	Genre MostSeenGenres1 = help_getMaximumValue(freqMap3).first;
//     string g1 = MovieDatabase.getGenres().at(MostSeenGenres1-1);
//     freqMap3.erase(MostSeenGenres1);
//     cout << "#1 Genre: "<<g1<<" "<<help_getMaximumValue(freqMap3).second<<" movies"<<endl;
	
//     Genre MostSeenGenres2 = help_getMaximumValue(freqMap3).first;
//     string g2 = MovieDatabase.getGenres().at(MostSeenGenres2-1);
// 	freqMap3.erase(MostSeenGenres2);
//     cout << "#2 Genre: "<<g2<<" "<<help_getMaximumValue(freqMap3).second<<" movies"<<endl;
	
//     Genre MostSeenGenres3 = help_getMaximumValue(freqMap3).first;
// 	string g3 = MovieDatabase.getGenres().at(MostSeenGenres3-1);
//     freqMap3.erase(MostSeenGenres3);
//     cout << "#3 Genre: "<<g3<<" "<<help_getMaximumValue(freqMap3).second<<" movies"<<endl;
// }


// TEST(getRec, directorFrequence_template2){
//    movieList MovieDatabase;
//    MovieDatabase.readMovieListFiles();
//    vector<movie> MovieList = MovieDatabase.returnList();
//    //get all the years of Database and calculate its frequency
//    vector<string>dir;
//    for(auto x: MovieList){
//        dir.push_back(x.getDirector());
//    }
//    //using a map to store year:frequency
//    map<string, int> freqMap = help_getFreq(dir);
//    // 	for (auto& it : freqMap) {
//    //      cout << it.first << ' '
//    //           << it.second << endl;
//    //  }
//    cout << "#1 director: "<<help_getMaximumValue(freqMap).first<<" "<<help_getMaximumValue(freqMap).second<<endl;
// }

// TEST(UsergetRec, 1movie){
//     vector<movie> rec;
// 	vector<int> yearlist;
// 	vector<string>directorlist;
// 	vector<Genre> genreslist;
	
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     vector <movie> filteredList = MovieDatabase.returnList();
    
//     //making a top 30 list 0f 2018. 
//     MovieDatabase.makeLatestTop30(2018);
// 	vector<movie> latest30 = MovieDatabase.returnLatestTop30();

    
//     vector<movie> tempFav;
//     for(int i = 0; i <= 100; i ++){
// 	tempFav.push_back(MovieDatabase.returnList().at(i));
//     }
//     for(movie x: tempFav){ 
//         yearlist.push_back(x.getYear());
// 		directorlist.push_back(x.getDirector());
// 		for(Genre y: x.genre_list){
// 			genreslist.push_back(y);
// 		}
// 	}

// 	int year1=0;
// 	Genre gen1;
// 	string director1;
   
//     year1 = help_getTopFreq(yearlist);	
//     director1 = help_getTopFreq(directorlist);	
//     gen1 = help_getTopFreq(genreslist);	
    
//     cout<<"top year: "<< year1<<endl;
//     cout<<"director: "<<director1<<endl;
//     cout<<"genra: "<<gen1<<endl;
//     vector <movie> filteredList1,filteredList2,filteredList3;
//     int A, B, C; //size of filteredList1, filteredList2, filteredList3

//     //Begin filtering
//     filteredList1 = MovieDatabase.searchYearRange_2(year1, year1, filteredList);
//     A = filteredList1.size();
//     if (A!=0){

//         filteredList2 = MovieDatabase.searchByGenre_2(gen1,filteredList1);
//         B = filteredList2.size();
        
//         if(B!=0){

//             filteredList3 = MovieDatabase.searchByDirector(director1,filteredList);
//             C = filteredList3.size();
//         }
      
//     }

//     if(A<30){rec = filteredList1;}
//     else if(B<30){rec =filteredList2;}
//     else {rec = filteredList3;}

// 	int recSize = rec.size();
// 	if(recSize<30){
// 		int j = 0;
// 		for(int i = recSize; i<30; i++){
// 			rec.push_back(latest30.at(j++));
// 		}
		
// 	}

    
// cout<<"filter1 size : "<<A<<endl;
// cout<<"filter2 size : "<<B<<endl;
// cout<<"filter3 size : "<<C<<endl;
//     cout<<"exit filter"<<endl;
//     cout<<"rec list size: "<<rec.size()<<endl;
//     // for (auto x : rec){
//     //     x.printMovie();
//     // }
    
// }

// TEST(UsergetRec, 2movies){
// 	vector<movie> rec;
// 	vector<int> yearlist;
// 	vector<Genre> genreslist;


// movieList MovieDatabase;
// MovieDatabase.readMovieListFiles();
// vector <movie> filteredList = MovieDatabase.returnList();


// 	int year1, year2;
// 	Genre gen1, gen2;
// 	year1 = 2010; year2 = 2013; gen1 = Crime; gen2 = Horror;
// 	vector <movie> filteredList1,filteredList2,filteredList3,filteredList4, rec1, rec2, rec3, rec4 ; 
//    	int A, B, C, D = 0; //size of filteredList1, filteredList2, filteredList3, filteredList4
	

// 		//Begin filtering
		
// 		filteredList1 = MovieDatabase.searchYearRange_2(year1, year1, filteredList);
// 		A = filteredList1.size();

// 		std::cout<<"A size: "<<A<<endl;
				
// 			//(year1 && gen1) 
// 			filteredList2 = MovieDatabase.searchByGenre_2(gen1,filteredList1);
// 			B = filteredList2.size();
	
// 		std::cout<<"B size: "<<B<<endl;
// 			//(year1 && gen2)
// 			filteredList3 = MovieDatabase.searchByGenre_2(gen2,filteredList1);
// 			C = filteredList3.size();
// 		std::cout<<"C size: "<<C<<endl;
// 			//(year1 && gen1) U (year1 && gen2)
// 			MovieDatabase.mergeList(filteredList2,filteredList3, filteredList4);
// 			D = filteredList4.size();
// 		std::cout<<"D size: "<<D<<endl;
// 			for(int i = 0; i < 5; i++){
// 			std::cout<<filteredList4.at(i).getYear()<<endl;
// 		}
// 			if(D>10){
// 				MovieDatabase.sortByRatingDescending_2(filteredList4);
// 				for(int i = 0 ; i < 10 ; i ++){
// 					rec1.push_back(filteredList4.at(i));
// 				}
// 			}
// 			else {
// 				rec1 = filteredList4;
// 			}
// 		for(auto x: rec1){
//             std::cout<<x.getTitle()<<" "<<x.getYear()<<endl;
			
//         }

// 		if(year1!=year2){
// 			//filtering: year2 + gen1 + gen2 + high rate		
// 				filteredList1 = MovieDatabase.searchYearRange_2(year2, year2, filteredList);
// 				A = filteredList1.size();
					
// 				//(year2 && gen1) 
// 				filteredList2 = MovieDatabase.searchByGenre_2(gen2,filteredList1);
// 				B = filteredList2.size();
// 			std::cout<<" test B size:"<< B<<endl;
// 				//(year2 && gen2)
// 				filteredList3 = MovieDatabase.searchByGenre_2(gen2,filteredList1);
// 				C = filteredList3.size();
// 			std::cout<<" test C size:"<<C<<endl;

// 				//(year2 && gen1) U (year2 && gen2)
// 				MovieDatabase.mergeList(filteredList2,filteredList3, filteredList4);
// 				D = filteredList4.size();
// 			std::cout<<" test D size:"<< D<<endl;
// 				if(D>10){
// 					MovieDatabase.sortByRatingDescending_2(filteredList4);
// 					for(int i = 0 ; i < 10 ; i ++){
// 						rec2.push_back(filteredList4.at(i));
// 					}
// 				}
// 				else {
// 					rec2 = filteredList4;
// 				}
// 				MovieDatabase.mergeList(rec1, rec2, rec3);


// 				rec = rec3;
// 		}
// 		else{
// 			rec = rec1;
// 		}
			

//         for(auto x: rec){
//             std::cout<<x.getTitle()<<" "<<x.getYear()<<endl;
			
//         }
//         std::cout<<"rec1 size: "<< rec1.size()<<endl;
//         std::cout<<"rec2 size: "<< rec2.size()<<endl;
//         std::cout<<"rec size: "<< rec.size()<<endl;
//         std::cout<<"gen1: "<<gen1<<endl;
//         std::cout<<"gen2: "<<gen2<<endl;
		
    
// }

int main(int argc, char **argv) {
    srand(time(0));
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
