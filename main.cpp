//#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>  
#include <stdlib.h> 

#include "json/json.hpp"
#include "movie.h"

using namespace std;
using json = nlohmann::json;

void printMovie(movie);

int main(){

                   
    std::ifstream f("data/metadata_updated.json");
    json data = json::parse(f);

    vector <movie> movieList;
    
    for (int i=0; i <8000; i++){
    string temp = data[i]["imdbId"];
    int imbd = atoi(temp.c_str());
 
   movie m1 (data[i]["title"],data[i]["directedBy"],data[i]["starring"],data[i]["avgRating"],imbd,data[i]["item_id"]);
   movieList.push_back(m1);
    printMovie(movieList.at(i));
    cout<<endl;
}

}

 void printMovie(movie m){
    cout<<"title: "<<m.title<<endl;
    cout<<"director: "<<m.director<<endl;
    cout<<"casting: "<<m.cast<<endl;
    cout<<"rating: "<<m.rating<<endl;
    cout<<"IMDB ID: "<<m.imbdId<<endl;
    cout<<"item: "<<m.itemId<<endl;
 };

    
