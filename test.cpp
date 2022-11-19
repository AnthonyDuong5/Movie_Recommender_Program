#include "movie.hpp"
#include "movieList.hpp"
#include "user.hpp"
#include "menu.hpp"
#include "gtest/gtest.h"
#include <vector>
#include <cstdlib>

TEST(VectorTest, testException) {
    EXPECT_NO_THROW({
        vector<movie> movieList;
    });
}

TEST(SortTest, testSortByRatingDescending) {
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.sortByRatingDescending();
    MovieDatabase.printMovies();
}

TEST(SortTest, testSortByRatingAscending) {
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.sortByRatingAscending();
    MovieDatabase.printMovies();
    
}

TEST(SortTest, testSearchByRatings) {
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.searchByRatings(4.0, 4.5);
    cout << "--------------------------------------------------" << endl;
    cout << "title: " << MovieDatabase.returnSortedList().front().getTitle() << endl;
    cout << "year: " << MovieDatabase.returnSortedList().front().getYear() << endl;
    cout << "director: " << MovieDatabase.returnSortedList().front().getDirector() << endl;
    cout << "casting: " << MovieDatabase.returnSortedList().front().getCast() << endl;
    cout << "rating: " << MovieDatabase.returnSortedList().front().getRating() << endl;
    cout << "imbdid: " << MovieDatabase.returnSortedList().front().getImdbId() << endl;
    cout << "itemid: " << MovieDatabase.returnSortedList().front().getItemId() << endl;
    cout << "genre: ";
    for (auto genre : MovieDatabase.returnSortedList().front().getGenreList()) {cout << genre << " ";} 
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    for (unsigned i = 100; i < 1100; i += 100) {
        cout << "--------------------------------------------------" << endl;
		cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
		cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
		cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
		cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
		cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
		cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
		cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
		cout << "genre: ";
        for (auto genre : MovieDatabase.returnSortedList().at(i).getGenreList()) {cout << genre << " ";} 
        cout << endl;
        cout << "--------------------------------------------------" << endl;
	}
    cout << "--------------------------------------------------" << endl;
    cout << "title: " << MovieDatabase.returnSortedList().back().getTitle() << endl;
    cout << "year: " << MovieDatabase.returnSortedList().back().getYear() << endl;
    cout << "director: " << MovieDatabase.returnSortedList().back().getDirector() << endl;
    cout << "casting: " << MovieDatabase.returnSortedList().back().getCast() << endl;
    cout << "rating: " << MovieDatabase.returnSortedList().back().getRating() << endl;
    cout << "imbdid: " << MovieDatabase.returnSortedList().back().getImdbId() << endl;
    cout << "itemid: " << MovieDatabase.returnSortedList().back().getItemId() << endl;
    cout << "genre: ";
    for (auto genre : MovieDatabase.returnSortedList().back().getGenreList()) {cout << genre << " ";} 
    cout << endl;
    cout << "--------------------------------------------------" << endl;
}

TEST(SortTest, testSortAscendingTitles) {
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.sortAscendingTitles(MovieDatabase.returnList());
	MovieDatabase.printMovies();
}

TEST(SortTest, testSortDescendingTitles) {
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.sortDescendingTitles(MovieDatabase.returnList());
    MovieDatabase.printMovies();
}

TEST (SortTest, testSearchMovieTitle){
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.searchMovieTitle("Hotel");
    MovieDatabase.printMovies();
    
}

TEST(SortByYearTest, SortAscending) {
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.sortByYearAscending();
    MovieDatabase.printMovies();
    
}

TEST(SortByYearTest, SortDescending) {
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.sortByYearDescending();
    MovieDatabase.sortByYearDescending();
    for (unsigned i = 0; i < 5000; i+=500) {
        cout << "--------------------------------------------------" << endl;
		cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
		cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
		cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
		cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
		cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
		cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
		cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
		cout << "genre: ";
        for (auto genre : MovieDatabase.returnSortedList().at(i).getGenreList()) {cout << genre << " ";} 
        cout << endl;
        cout << "--------------------------------------------------" << endl;
	}
}

TEST(SortByYearTest, SelectYearRange) {
	movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.searchYearRange(1990, 1995);
    for (unsigned i = 0; i < 750 ; i+=50) {
        cout << "--------------------------------------------------" << endl;
		cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
		cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
		cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
		cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
		cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
		cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
		cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
        		cout << "genre: ";
        for (auto genre : MovieDatabase.returnSortedList().at(i).getGenreList()) {cout << genre << " ";} 
        cout << endl;
        cout << "--------------------------------------------------" << endl;
	}
}

TEST(SortByGenres, testGenreList){
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    cout << "database has been set, print genres" << endl;
    MovieDatabase.printGenres();
    cout << "finish printing genres."<<endl;

    EXPECT_EQ(MovieDatabase.getGenres().size(),19);
}

     TEST(SortByGenres, searchByGenre_Genre){
        movieList MovieDatabase;
        MovieDatabase.readMovieListFiles();
        cout << "database has been set" << endl;
        Genre gType = Mystery; 
        vector<movie> genreMovieList = MovieDatabase.searchByGenre(gType);
        cout << genreMovieList.size()<< " movies from Mystery."<<endl;
        for (unsigned i = 0; i < 10; i ++) {
            cout << "--------------------------------------------------" << endl;
            cout << "title: " << genreMovieList.at(i).getTitle() << endl;
            cout << "rating: " << genreMovieList.at(i).getRating() << endl;
            cout << "genre: " ;
            for (auto gen : genreMovieList.at(i).getGenreList()){cout<<gen<<" ";}cout<<endl;
            cout << "--------------------------------------------------" << endl;
        }
     }

TEST(SortByGenres, searchByGenre_int){
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    cout << "database has been set" << endl;
    int input = 1; 
    vector<movie> genreMovieList = MovieDatabase.searchByGenre(input);
    cout << genreMovieList.size()<< " movies from Adventure."<<endl;
    for (unsigned i = 0; i < 10; i ++) {
        cout << "--------------------------------------------------" << endl;
        cout << "title: " << genreMovieList.at(i).getTitle() << endl;
        cout << "rating: " << genreMovieList.at(i).getRating() << endl;
        cout << "genre: " ;
        for (auto gen : genreMovieList.at(i).getGenreList()){cout<<gen<<" ";}cout<<endl;
        cout << "--------------------------------------------------" << endl;
    }
}

TEST(movie, printmovie){
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    vector<movie> MovieList = MovieDatabase.returnList();
    for (movie x: MovieList){
        x.printMovie();
    }
    cout<<MovieList.size()<<" movies"<<endl;
}

TEST(getRec, yearFrequence){
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    vector<movie> MovieList = MovieDatabase.returnList();
    //get all the years of Database and calculate its frequency
    vector<int>yearlist;
    for(auto x: MovieList){
        yearlist.push_back(x.getYear());
    }
    //using a map to store year:frequency
    map<int, int> freqMap;
	for( int x : yearlist){
		if(freqMap.find(x)==freqMap.end()){
			freqMap[x]=1;
		}
		else{
			freqMap[x]++;
		}
	}
	
	for (auto& it : freqMap) {
        cout << it.first << ' '
             << it.second << endl;
    }
    cout << help_getMaximumValue(freqMap).first<<endl;
}


TEST(getRec, yearFrequence_template){

    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    vector<movie> MovieList = MovieDatabase.returnList();
    //get all the years of Database and calculate its frequency
    vector<int>yearlist;
    for(auto x: MovieList){
        yearlist.push_back(x.getYear());
    }
    //using a map to store year:frequency
    map<int, int> freqMap = help_getFreq(yearlist);
    cout << "#1 year: "<<help_getMaximumValue(freqMap).first<<" "<<help_getMaximumValue(freqMap).second<<endl;
}


TEST(getRec, directorFrequence_template){
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    vector<movie> MovieList = MovieDatabase.returnList();
    vector<string>dir;
    for(auto x: MovieList){
        dir.push_back(x.getDirector());
    }
    
    map<string, int> freqMap = help_getFreq(dir);
    // 	for (auto& it : freqMap) {
    //      cout << it.first << ' '
    //           << it.second << endl;
    //  }
    cout << "#1 director: "<<help_getMaximumValue(freqMap).first<<" "<<help_getMaximumValue(freqMap).second<<endl;
}

TEST(getRec, genreFrequence_template){
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    vector<movie> MovieList = MovieDatabase.returnList();
    //get all the years of Database and calculate its frequency
    vector<Genre> genres;
	for (auto x: MovieList){
		for(auto y: x.genre_list){
			genres.push_back(y);
		}
	}
    map<Genre, int> freqMap3 = help_getFreq(genres);	
	Genre MostSeenGenres1 = help_getMaximumValue(freqMap3).first;
    string g1 = MovieDatabase.getGenres().at(MostSeenGenres1-1);
    freqMap3.erase(MostSeenGenres1);
    cout << "#1 Genre: "<<g1<<" "<<help_getMaximumValue(freqMap3).second<<" movies"<<endl;
	
    Genre MostSeenGenres2 = help_getMaximumValue(freqMap3).first;
    string g2 = MovieDatabase.getGenres().at(MostSeenGenres2-1);
	freqMap3.erase(MostSeenGenres2);
    cout << "#2 Genre: "<<g2<<" "<<help_getMaximumValue(freqMap3).second<<" movies"<<endl;
	
    Genre MostSeenGenres3 = help_getMaximumValue(freqMap3).first;
	string g3 = MovieDatabase.getGenres().at(MostSeenGenres3-1);
    freqMap3.erase(MostSeenGenres3);
    cout << "#3 Genre: "<<g3<<" "<<help_getMaximumValue(freqMap3).second<<" movies"<<endl;
}


TEST(getRec, directorFrequence_template2){
   movieList MovieDatabase;
   MovieDatabase.readMovieListFiles();
   vector<movie> MovieList = MovieDatabase.returnList();
   //get all the years of Database and calculate its frequency
   vector<string>dir;
   for(auto x: MovieList){
       dir.push_back(x.getDirector());
   }
   //using a map to store year:frequency
   map<string, int> freqMap = help_getFreq(dir);
   // 	for (auto& it : freqMap) {
   //      cout << it.first << ' '
   //           << it.second << endl;
   //  }
   cout << "#1 director: "<<help_getMaximumValue(freqMap).first<<" "<<help_getMaximumValue(freqMap).second<<endl;
}

// TEST(UserMenu, RandomMovies) {
//      Menu menu1;
// }

int main(int argc, char **argv) {
    srand(time(0));
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
