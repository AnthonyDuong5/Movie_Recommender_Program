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
//     for (unsigned i = 0; i < 10000; i += 1000) {
//         cout << "--------------------------------------------------" << endl;
// 		cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
// 		cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
// 		cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
// 		cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
// 		cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
// 		cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
// 		cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
// 		cout << "genre: ";
//         for (auto genre : MovieDatabase.returnSortedList().at(i).getGenreList()) {cout << genre << " ";} 
//         cout << endl;
//         cout << "--------------------------------------------------" << endl;
// 	}
// }

// TEST(SortTest, testSortByRatingAscending) {
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.sortByRatingAscending();
//     for (unsigned i = 0; i < 10000; i += 1000) {
//         cout << "--------------------------------------------------" << endl;
// 		cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
// 		cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
// 		cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
// 		cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
// 		cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
// 		cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
// 		cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
// 		cout << "genre: ";
//         for (auto genre : MovieDatabase.returnSortedList().at(i).getGenreList()) {cout << genre << " ";} 
//         cout << endl;
//         cout << "--------------------------------------------------" << endl;
// 	}
// }

// TEST(SortTest, testSearchByRatings) {
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.searchByRatings(4.0, 4.5);
//     cout << "--------------------------------------------------" << endl;
//     cout << "title: " << MovieDatabase.returnSortedList().front().getTitle() << endl;
//     cout << "year: " << MovieDatabase.returnSortedList().front().getYear() << endl;
//     cout << "director: " << MovieDatabase.returnSortedList().front().getDirector() << endl;
//     cout << "casting: " << MovieDatabase.returnSortedList().front().getCast() << endl;
//     cout << "rating: " << MovieDatabase.returnSortedList().front().getRating() << endl;
//     cout << "imbdid: " << MovieDatabase.returnSortedList().front().getImdbId() << endl;
//     cout << "itemid: " << MovieDatabase.returnSortedList().front().getItemId() << endl;
//     cout << "genre: ";
//     for (auto genre : MovieDatabase.returnSortedList().front().getGenreList()) {cout << genre << " ";} 
//     cout << endl;
//     cout << "--------------------------------------------------" << endl;
//     for (unsigned i = 100; i < 1100; i += 100) {
//         cout << "--------------------------------------------------" << endl;
// 		cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
// 		cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
// 		cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
// 		cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
// 		cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
// 		cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
// 		cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
// 		cout << "genre: ";
//         for (auto genre : MovieDatabase.returnSortedList().at(i).getGenreList()) {cout << genre << " ";} 
//         cout << endl;
//         cout << "--------------------------------------------------" << endl;
// 	}
//     cout << "--------------------------------------------------" << endl;
//     cout << "title: " << MovieDatabase.returnSortedList().back().getTitle() << endl;
//     cout << "year: " << MovieDatabase.returnSortedList().back().getYear() << endl;
//     cout << "director: " << MovieDatabase.returnSortedList().back().getDirector() << endl;
//     cout << "casting: " << MovieDatabase.returnSortedList().back().getCast() << endl;
//     cout << "rating: " << MovieDatabase.returnSortedList().back().getRating() << endl;
//     cout << "imbdid: " << MovieDatabase.returnSortedList().back().getImdbId() << endl;
//     cout << "itemid: " << MovieDatabase.returnSortedList().back().getItemId() << endl;
//     cout << "genre: ";
//     for (auto genre : MovieDatabase.returnSortedList().back().getGenreList()) {cout << genre << " ";} 
//     cout << endl;
//     cout << "--------------------------------------------------" << endl;
// }

// TEST(SortTest, testSortAscendingTitles) {
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.sortAscendingTitles();
//     // for (unsigned i = 0; i < 100; i += 4) {
//     //     cout << "--------------------------------------------------" << endl;
// 	// 	cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
// 	// 	cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
// 	// 	cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
// 	// 	cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
// 	// 	cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
// 	// 	cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
// 	// 	cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
// 	// 	cout << "genre: " << MovieDatabase.returnSortedList().at(i).getGenre() << endl;
//     //     cout << "--------------------------------------------------" << endl;
//     // }
// 	MovieDatabase.printMovies();
// }

// TEST(SortTest, testSortDescendingTitles) {
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.sortDescendingTitles();
//     for (unsigned i = 0; i < 100; i += 4) {
//         cout << "--------------------------------------------------" << endl;
// 		cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
// 		cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
// 		cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
// 		cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
// 		cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
// 		cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
// 		cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
// 		cout << "genre: " << MovieDatabase.returnSortedList().at(i).getGenre() << endl;
//         cout << "--------------------------------------------------" << endl;
//     }
// }

TEST (SortTest, testSearchMovieTitle){
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.searchMovieTitle("Hotel");
    //MovieDatabase.printMovies();
    for (unsigned i = 0; i < 4; ++i) {
        cout << "--------------------------------------------------" << endl;
		cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
		cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
		cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
		cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
		cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
		cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
		cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
		cout << "genre: " ;
		for (auto gen : MovieDatabase.returnSortedList().at(i).getGenreList()){cout<<gen<<" ";}cout<<endl;
        cout << "--------------------------------------------------" << endl;
    }   
}

// TEST(SortByYearTest, SortAscending) {
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.sortByYearAscending();
//     for (unsigned i = 0; i < 400; i+=40) {
//         cout << "--------------------------------------------------" << endl;
// 		cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
// 		cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
// 		cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
// 		cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
// 		cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
// 		cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
// 		cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
// 		cout << "genre: ";
//         for (auto genre : MovieDatabase.returnSortedList().at(i).getGenreList()) {cout << genre << " ";} 
//         cout << endl;
//         cout << "--------------------------------------------------" << endl;
// 	}
// }

// TEST(SortByYearTest, SortDescending) {
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.sortByYearDescending();
//     for (unsigned i = 0; i < 5000; i+=500) {
//         cout << "--------------------------------------------------" << endl;
// 		cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
// 		cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
// 		cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
// 		cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
// 		cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
// 		cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
// 		cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
// 		cout << "genre: ";
//         for (auto genre : MovieDatabase.returnSortedList().at(i).getGenreList()) {cout << genre << " ";} 
//         cout << endl;
//         cout << "--------------------------------------------------" << endl;
// 	}
// }

// TEST(SortByYearTest, SelectYearRange) {
// 	movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.searchYearRange(1990, 1995);
//     for (unsigned i = 0; i < 750 ; i+=50) {
//         cout << "--------------------------------------------------" << endl;
// 		cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
// 		cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
// 		cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
// 		cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
// 		cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
// 		cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
// 		cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
//         		cout << "genre: ";
//         for (auto genre : MovieDatabase.returnSortedList().at(i).getGenreList()) {cout << genre << " ";} 
//         cout << endl;
//         cout << "--------------------------------------------------" << endl;
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

    //  TEST(SortByGenres, searchByGenre_Genre){
    //     movieList MovieDatabase;
    //     MovieDatabase.readMovieListFiles();
    //     cout << "database has been set" << endl;
    //     Genre gType = Mystery; 
    //     vector<movie> genreMovieList = MovieDatabase.searchByGenre(gType);
    //     cout << genreMovieList.size()<< " movies from Mystery."<<endl;
    //     for (unsigned i = 0; i < 10; i ++) {
    //         cout << "--------------------------------------------------" << endl;
    //         cout << "title: " << genreMovieList.at(i).getTitle() << endl;
    //         cout << "rating: " << genreMovieList.at(i).getRating() << endl;
    //         cout << "genre: " ;
    //         for (auto gen : genreMovieList.at(i).getGenreList()){cout<<gen<<" ";}cout<<endl;
    //         cout << "--------------------------------------------------" << endl;
    //     }
    //  }

// TEST(SortByGenres, searchByGenre_int){
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     cout << "database has been set" << endl;
//     int input = 1; 
//     vector<movie> genreMovieList = MovieDatabase.searchByGenre(input);
//     cout << genreMovieList.size()<< " movies from Adventure."<<endl;
//     for (unsigned i = 0; i < 10; i ++) {
//         cout << "--------------------------------------------------" << endl;
//         cout << "title: " << genreMovieList.at(i).getTitle() << endl;
//         cout << "rating: " << genreMovieList.at(i).getRating() << endl;
//         cout << "genre: " ;
//         for (auto gen : genreMovieList.at(i).getGenreList()){cout<<gen<<" ";}cout<<endl;
//         cout << "--------------------------------------------------" << endl;
//     }
// }

TEST(UserMenu, RandomMovies) {
    Menu menu1;
}


int main(int argc, char **argv) {
    srand(time(0));
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}