#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>  
#include <stdlib.h> 

#include "json/json.hpp"
#include "movie.h"

using namespace std;
using json = nlohmann::json;

void printMovie(const movie&);
void getYear(movie&);
void clean(vector<movie>&);

int main(){

                   
    std::ifstream f("data/metadata_updated.json");
    json data = json::parse(f);
    vector <movie> movieList;
    int i = 0;
    for (i= 0; i <data.size(); i++){
       
        string temp = data[i]["imdbId"];
        int imbd = atoi(temp.c_str()); 

        movie m1 (data[i]["title"],data[i]["directedBy"],data[i]["starring"],data[i]["avgRating"],imbd,data[i]["item_id"]);
        getYear(m1);
        movieList.push_back(m1);
       
    }
    cout<< "data size = "<< data.size() << endl;
    cout<< "Movie list initially has: " << i <<" items." << endl;
    clean(movieList);

}

 void printMovie(const movie &m){
    cout<<"title: "<<m.title<<endl;
    cout<<"year: "<<m.year<<endl;
    cout<<"director: "<<m.director<<endl;
    cout<<"casting: "<<m.cast<<endl;
    cout<<"rating: "<<m.rating<<endl;
    cout<<"IMDB ID: "<<m.imbdId<<endl;
    cout<<"item: "<<m.itemId<<endl;
 };
 void getYear(movie &m){
    string title = m.title;
    for(int i = 0; i < title.size(); i++){
        if(title.at(i)=='('&& (title.at(i+1)=='1'||title.at(i+1)=='2')){
            m.year = (int(title.at(i+1))-48)*1000 +
                     (int(title.at(i+2))-48)*100  +
                     (int(title.at(i+3))-48)*10   +
                     (int(title.at(i+4))-48); 
            break;
        }
        else (m.year = 0);
    }
 }
 void clean(vector<movie> &m){
    vector<movie>::iterator it;
    //Part1: check Year
    for ( it = m.begin(); it < m.end(); it++){
        if (it->year <1990){
            it=m.erase(it);
        }
    }
    int j = m.size();
    cout << j << " movies from 1990." << endl;

    double minRating = 3.5;
    for( it = m.begin();it < m.end(); it++){
        if(it->rating < minRating){
            it=m.erase(it);
        }
    }
    int listQty = m.size();
    cout << listQty << " movies with a rating higher than " << minRating << endl;
    
 }