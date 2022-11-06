#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>  
#include <stdlib.h> 

#include "json/json.hpp"
#include "movie.hpp"
#include "movieList.hpp"

using namespace std;
using json = nlohmann::json;

void printMovie(const movie&);
void getYear(movie&);

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
        printMovie(movieList.at(i));
        
        cout<<endl;
       
    }
    cout<<i<<" items."<<endl;

}

 void printMovie(const movie &m){
    cout<<"title: "<< m.getTitle()<<endl;
    cout<<"year: "<< m.getYear()<<endl;
    cout<<"director: "<<m.getDirector()<<endl;
    cout<<"casting: "<<m.getCast()<<endl;
    cout<<"rating: "<<m.getRating()<<endl;
    cout<<"IMDB ID: "<<m.getImdbId()<<endl;
    cout<<"item: "<<m.getItemId()<<endl;
 };
 void getYear(movie &m){
    string title = m.getTitle();
    for(int i = 0; i < title.size(); i++){
        if(title.at(i)=='('&& (title.at(i+1)=='1'||title.at(i+1)=='2')){
            // m.getYear() = (int(title.at(i+1))-48)*1000 +
            //          (int(title.at(i+2))-48)*100  +
            //          (int(title.at(i+3))-48)*10   +
            //          (int(title.at(i+4))-48); 
            int movieYear = (int(title.at(i+1))-48)*1000 + (int(title.at(i+2))-48)*100  +
                            (int(title.at(i+3))-48)*10   + (int(title.at(i+4))-48); 
            m.setYear(movieYear);
            break;
        }
        else (m.setYear(0));
    }
 }