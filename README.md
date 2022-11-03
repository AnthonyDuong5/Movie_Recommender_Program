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
 
![Movie Recommender](https://user-images.githubusercontent.com/74810222/199172861-30c0a5e7-519a-4892-9e39-902ac3c33684.png)


## Diagram Description
The current plan is to create three classes. The ```Movie``` class will store all the necessary categories that each movie has, such as ```MovieTitle```, ```Director```, ```Cast```, ```Rating```, ```ImdbID```, ```ItemID```, ```Genre```, and ```Year```, all of which will be set to private. There will be helper functions that can help the programmer retrieve values for each of these variables.

This brings us to the next class, ```MovieList```. ```MovieList``` will be the class that needs the most implementation, as there will be many different functions. We will firstly have two declared vectors, namely ```vector<Movie>List``` and ```vector<Movie>SortedList```. The difference is that the former will contain all the movies before the sorting has been done, while the latter will only contain sorted values. There will be a function called ```readMovieListFile()``` that will be used to read a database of movies and store them into the ```vector<Movie>List```. So far, we will only implement it for ```.json``` files, but we will look to expand to ```.txt``` and ```.csv``` files as well. The ```sortList()``` function will run individual sort functions depending on user input. For example, if the user wants to sort by Movie Title, it will call the function ```sortByMovieTitle()```. Lastly, there will also be the function that prints the sorted List, called ```printList()```.

Users of this Movie Recommender can view recommended movies though the ```User``` class interface. An object of type ```User``` holds private data members ```UserID``` and ```ViewedMovies```. Since the ```User``` class is associated with the ```MovieList``` class, ```User``` objects have public methods such as getters for ```UserID``` and ```ViewedMovies```, adding movies to the list, and receiving recommendations for movies based on user-provided criteria. The menu will be displayed so that users can interact with the program. The ```getViewedMovies()``` method will return a list of movies that the user has specifically searched for by name, in addition to movies that have been recommended to them. ```addMovieToList()``` will add the movie to a private user list after the user has finished filtering/sorting movies in ```MovieList```, and the user would be able to view the list of movies by calling the ```printList()``` function in the ```MovieList``` Class.
 
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 > * Before the meeting you should perform a sprint plan like you did in Phase I.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
