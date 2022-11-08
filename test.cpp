#include "movie.hpp"
#include "movieList.hpp"
#include "gtest/gtest.h"

TEST(VectorTests, testException) {
    EXPECT_NO_THROW({
        vector<movie> movieList;
    });
}

TEST(SortTests, testSortByRating) {
    movieList MovieDatabase;
    MovieDatabase.readMovieListFiles();
    MovieDatabase.sortByRating();
    for (unsigned i = 0; i < 10000; i += 1000) {
        cout << "--------------------------------------------------" << endl;
		cout <<"title: " << MovieDatabase.returnList().at(i).getTitle() << endl;
		cout <<"year: " << MovieDatabase.returnList().at(i).getYear() << endl;
		cout <<"director: " << MovieDatabase.returnList().at(i).getDirector() << endl;
		cout <<"casting: " << MovieDatabase.returnList().at(i).getCast() << endl;
		cout <<"rating: " << MovieDatabase.returnList().at(i).getRating() << endl;
		cout <<"imbdid: " << MovieDatabase.returnList().at(i).getImdbId() << endl;
		cout <<"itemid: " << MovieDatabase.returnList().at(i).getItemId() << endl;
		cout <<"genre: " << MovieDatabase.returnList().at(i).getGenre() << endl;
        cout << "--------------------------------------------------" << endl;
	}
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}