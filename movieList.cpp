#include "movieList.hpp"
#include <string>
#include <vector>
#include "json/json.hpp"
#include "movie.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include <iostream>

using namespace std;
using json = nlohmann::json;

movieList::movieList(){}


void movieList::readMovieListFiles(){

	//read json file.
	fstream f("data/newdata.json");
    json moviedata = json::parse(f);

    int countMovies = 0;
	for (countMovies = 0; countMovies < moviedata.size(); ++countMovies){

		
		movie Movie1 (moviedata[countMovies]["title"], moviedata[countMovies]["directedBy"], 
					  moviedata[countMovies]["starring"], moviedata[countMovies]["avgRating"],
					  moviedata[countMovies]["imdbId"], moviedata[countMovies]["item_id"], moviedata[countMovies]["year"], moviedata[countMovies]["genresList"]);
		
		list.push_back(Movie1);
		
	
	}

	
    json newdata;
    vector<movie>::iterator i;
    std::ofstream out("data/newdata2.json");
    for( i = list.begin();i < list.end(); i++){
       newdata["title"]=i->getTitle();
       newdata["directedBy"]=i->getDirector();
       newdata["starring"]=i->getCast();
       newdata["avgRating"]=i->getRating();
       newdata["imdbId"]=i->getImdbId();
       newdata["item_id"]=i->getItemId();
       newdata["year"]=i->getYear();
       newdata["genresList"]=i->getGenreList();

       out << setw(4) << newdata << endl;
    }
}





//sorts movies by rating in descending order
void movieList::sortByRating() {
	sortedlist = list;
	int maxIdx;

	for (unsigned i = 0; i + 1 < sortedlist.size(); ++i) {
		maxIdx = i;

		for (unsigned j = i + 1; j < sortedlist.size(); ++j) {
			if (sortedlist.at(j).getRating() > sortedlist.at(maxIdx).getRating()) {
				maxIdx = j;
			}
		}

		swap(sortedlist.at(i), sortedlist.at(maxIdx));
	}
}

void movieList::printMovies(){
	vector<movie> movieListPrint = returnSortedList();
	//temporarily changed m.size() to a fixed vector size
	for (int i =0; i < movieListPrint.size(); ++i){
		cout << "------------------" << endl;

		cout<<"title: "<< movieListPrint.at(i).getTitle()<<endl;
		cout<<"year: "<< movieListPrint.at(i).getYear()<<endl;
		cout<<"director: "<<movieListPrint.at(i).getDirector()<<endl;
		cout<<"casting: "<<movieListPrint.at(i).getCast()<<endl;
		cout<<"rating: "<<movieListPrint.at(i).getRating()<<endl;
		cout<<"IMDB ID: "<<movieListPrint.at(i).getImdbId()<<endl;
		cout<<"item: "<<movieListPrint.at(i).getItemId()<<endl;
		cout<<"Genre: "; for (auto gen : m.at(i).getGenreList()){ cout<<gen<<" ";} cout<<endl;

	}
}

void movieList::sortYear(vector<movie>& newList) {

	//can try to replace newList.size() to a fixed number to see the first movies in the list
	//i've tried it and it seems to work in the lower end of the list as well
	//note: last movie has an incorrect year and is in the wrong spot because of it
	
	int temp;
	for (int j = 0; j < newList.size() - 1; ++j){
		int min = newList.at(j).getYear();
		temp = j;
		for (int i = j+1; i < newList.size(); ++i) {
			if (min > newList.at(i).getYear()) {
				min = newList.at(i).getYear();
				temp = i;
			}
		}
		std::swap(newList.at(j), newList.at(temp));
	}
	//printMovies(newList);
}

// void movieList::sortByMovieTitle(string movieName) {

// }

void movieList::sortAscendingTitles(vector <movie>& l){
	sortedlist = l;
	int titleTop;
	for (unsigned i = 0; i < sortedlist.size(); ++i){
		titleTop = i;
		for (unsigned j = i + 1; j < sortedlist.size(); ++j){
			if (sortedlist.at(j).getTitle() < sortedlist.at(titleTop).getTitle() ){
				titleTop = j;
			}
		}
		swap (sortedlist.at(i), sortedlist.at(titleTop));
	}
}

void movieList::sortDescendingTitles(vector <movie>& l){
	sortedlist = l;
	int titleLast;
	for (unsigned i = 0; i < sortedlist.size(); ++i){
		titleLast = i;
		for (unsigned j = i + 1; j < sortedlist.size(); ++j){
			if (sortedlist.at(j).getTitle() > sortedlist.at(titleLast).getTitle() ){
				titleLast = j;
			}
		}
		swap (sortedlist.at(i), sortedlist.at(titleLast));
	}
}

void movieList::sortMovieByString(string m1){
	sortedlist = list;
	vector<movie> newList;
	string lowercasem1 = m1;
	string lowercasemsorted;
 
    // using transform() function and ::tolower in STL
    transform(lowercasem1.begin(), lowercasem1.end(), lowercasem1.begin(), ::tolower);
    cout<< "lowercase: " << lowercasem1<<endl;
 

	for (unsigned i = 0; i < sortedlist.size(); ++i){
		lowercasemsorted = sortedlist.at(i).getTitle();
		transform(lowercasemsorted.begin(), lowercasemsorted.end(), lowercasemsorted.begin(), ::tolower);
		if (lowercasemsorted.find(lowercasem1) != std::string::npos) {
    		//cout << "found!" << '\n';
			newList.push_back(returnSortedList().at(i));
		}
		
	}
	sortedlist = newList;
	//this is not sorted by alphabetical order, so we run sort ascending
	sortAscendingTitles(sortedlist);
}

 vector<movie>& movieList::returnList(){
	return list;
}

vector<movie>& movieList::returnSortedList() {
	return sortedlist;
}