#include "movie.hpp"

#include "gtest/gtest.h"

TEST(VectorTests, testException) {
    EXPECT_NO_THROW({
        vector<movie> movieList;
    });
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}