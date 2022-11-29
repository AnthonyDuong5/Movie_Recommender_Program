[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8862210&assignment_repo_type=AssignmentRepo)

# Movie Recommender
Authors: [Win Thant Tin Han](https://github.com/WinThant16), [Jeralson Paredes](https://github.com/jeralsonep), [Isabel Chen](https://github.com/issy16), [Anthony Duong](https://github.com/AnthonyDuong5)

# Description

In this application movies are organized into categories and subcategories to represent their genres and subgenres respectively. The application allows displaying movies under different genres/subgenres or listing movies using different combined ciritera (e.g. director and genre). A user can provide a name of a movie that he/she likes and the application can recommend a list of movies that the user might like. Different recommendation algorithms can be implemented (e.g. based on the movie genre, director, actors) and the resulting recommendations can also be sorted based on their rating, release date, etc.


## Project Description
This project will help us gain experience in creating software programs involving databases. We're interested in how we can implement a database into an algorithm that can display movies based on certain criteria.
We will be using C++ as our main programming language.
The user will use the keyboard to input desired movie criteria (e.g. genre, year, rating). The output will then be a list of movies that correlate with the given criteria. 
The movie recommender will allow users to find certain movies based on certain criteria. For example, users can provide a movie and the application will recommend a list of movies that are similar to the provided movie. Additionally, users can also sort lists of movies based on rating, release date, genre, etc.
 
## Class Diagram


![Movie Recommender (1)](https://user-images.githubusercontent.com/74810222/204652566-90e103e9-70e3-4475-8d06-7ed94eb193b2.png)



## Diagram Description
The current plan is to create four classes. The ```Movie``` class will store all the necessary categories that each movie has, such as ```MovieTitle```, ```Director```, ```Cast```, ```Rating```, ```ImdbID```, ```ItemID```, ```Genre```, and ```Year```, all of which will be set to private. There will be helper functions that can help the programmer retrieve values for each of these variables.

This brings us to the next class, ```MovieList```. ```MovieList``` will be the class that needs the most implementation, as there will be many different functions. We will firstly have two declared vectors, namely ```vector<Movie>List``` and ```vector<Movie>SortedList```. The difference is that the former will contain all the movies before the sorting has been done, while the latter will only contain sorted values. The third private data member is the the `vector<string>genres`, which stores a vector of 19 genres.Lastly, we have a `vector<movie>` called `latestTop30`, which stores the most recent highest rated movies.

As we can see from the UML Diagram included above, we have implemented several functions for the constructor of this class, creation of the movie file, and parsing as well. Then, we also have the necessary sort functions for each single category, like title, rating, year and genre. These functions will all modify the ```sortedList``` vector previously mentioned, and the vector will be used to display the output, which is called by the `printMovies()` function.
There will be a function called ```readMovieListFile()``` that will be used to read a database of movies and store them into the ```vector<Movie>List```. So far, we will only implement it for ```.json``` files. There are many individual sort functions depending on user input. For example, if the user wants to sort by Movie Title, it will call the function ```sortByMovieTitle()```. 

Users of this Movie Recommender can view recommended movies though the ```User``` class interface. An object of type ```User``` holds private data members ```UserName```, ```Favorites```, ```DefaultList```, ```ViewingList```, ```prompt``` and ```userFavList```, which will all be used to help the menu class carry out its work. Since the ```User``` class is associated with the ```Menu``` class, ```User``` objects have accessor functions like ```getFavoritesList()```, ```getDefaultList()``` and ```getViewingList```. Additionally, it will have a ```AddToFavorite(const movie&)``` function, which will add the movie of the User's choice to the object of `vector<movie>Favorites`. The class will also have helper functions like ```removeFromViewingList(unsigned)```, which will help the program remove movies that have been displayed by the `printTenRandomMovies()` function from the `Menu` Class. Most importantly, the `getRec()` function will be used to generate movies to recommend to the User based on the User's favorite list. Templates are also implemented in the class to help streamline the `getRec()` function.

The `Menu` Class will have the necessary functions for implementing a userinterface that would serve as a guide/menu for the User. It will contain functions such as `printMenu()` which displays available options of the program, `getPrompt()`, which asks the user for their choice of option with validation checks, and `processPrompt(const int&)`, which will call related functions according to the User's choices. Additionally, it will have a function called `getCriteria()`, which asks the user to choose a category for searching Movies, and `printTenRandomMovies()`, which can be used to display ten random movies to the User if they want to start there. The main function of this class will be the `searchMovies()`, which will start a process of filtering/searching for movies. The Menu class' functions will go hand in hand with the functions of the User class as the User will only be interacting with the program through the Menu class.
 

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 Run the following commands in terminal:

 1. setup directory

     `mkdir movieRec`

     `cd movieRec`
 
 2. clone repository

     `git clone --recursive https://github.com/cs100/final-project-aduon067-ichen064-jpare033-wtin001.git`
     
     `cd final-project-aduon067-ichen064-jpare033-wtin001`

 3. build movie recommender
 
    a. Either through CMake: 

    `cmake .`
   
    `make`
 
    b. or directly using g++: 

     `g++ -o movie_recommender main.cpp movie.cpp movieList.cpp user.cpp menu.cpp`

4. run movie recommender

     `./movie_recommender`

 ## Testing
  [![CI](https://github.com/cs100/final-project-aduon067-ichen064-jpare033-wtin001/actions/workflows/main.yml/badge.svg)](https://github.com/cs100/final-project-aduon067-ichen064-jpare033-wtin001/actions/workflows/main.yml)
  
 This movie recommender application is tested to make sure that movies are sorted and filtered correctly based on various criteria such as genre, rating, title, and year. The tests create a failure if two adjacent movies are not sorted in the correct order, if a movie does not belong within a filtered specification, or if there are other small errors in creating a movie list. The CI tool used is GitHub Actions, which shows a check if the cmake build and all tests pass. Alternatively, running the `test` executable after running `make` displays the same information.
 
