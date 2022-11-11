#include "movie.hpp"
#include "movieList.hpp"
#include "gtest/gtest.h"

TEST(VectorTests, testException) {
    EXPECT_NO_THROW({
        vector<movie> movieList;
    });
}

// TEST(SortTests, testSortByRating) {
//     movieList MovieDatabase;
//     MovieDatabase.readMovieListFiles();
//     MovieDatabase.sortByRating();
//     for (unsigned i = 0; i < 10000; i += 1000) {
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
// 	}
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

TEST (SortTest, testSortMovieByString){
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.sortMovieByString("THE");
    //MovieDatabase.printMovies();
    for (unsigned i = 0; i < 15; ++i) {
        cout << "--------------------------------------------------" << endl;
		cout << "title: " << MovieDatabase.returnSortedList().at(i).getTitle() << endl;
		cout << "year: " << MovieDatabase.returnSortedList().at(i).getYear() << endl;
		cout << "director: " << MovieDatabase.returnSortedList().at(i).getDirector() << endl;
		cout << "casting: " << MovieDatabase.returnSortedList().at(i).getCast() << endl;
		cout << "rating: " << MovieDatabase.returnSortedList().at(i).getRating() << endl;
		cout << "imbdid: " << MovieDatabase.returnSortedList().at(i).getImdbId() << endl;
		cout << "itemid: " << MovieDatabase.returnSortedList().at(i).getItemId() << endl;
		cout << "genre: " << MovieDatabase.returnSortedList().at(i).getGenre() << endl;
        cout << "--------------------------------------------------" << endl;
    }   
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}