CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(movie_recommender)
SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)
INCLUDE_DIRECTORIES(googletest/include)

ADD_EXECUTABLE(movie_recommender
    main.cpp
    movie.cpp
    movieList.cpp
)

ADD_EXECUTABLE(test
    test.cpp
    movie.cpp
    movieList.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)