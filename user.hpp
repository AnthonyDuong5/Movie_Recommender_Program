#ifndef __USERCLASS__
#define __USERCLASS__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>  
#include <stdlib.h> 
#include <algorithm> 

#include "json/json.hpp"
#include "movie.hpp"
#include "movieList.hpp"

using namespace std;

class User {
	private:
		string UserName;
		vector<movie> Favorites;
		vector<movie> DefaultList;
		vector<movie> ViewingList;
		int prompt = 0;

		//adding a movieList,can use funcions from the movieList
		movieList userFavList;

	public:
		User();

		void AddToFavorite(const movie& m1);
		vector <movie>& getFavoritesList(){ return Favorites;}
		vector<movie> getDefaultList(){return DefaultList;}
		vector<movie> getViewingList(){return ViewingList;}
		void removeFromViewingList(unsigned idx);

		//this function will use something from  movieList userFavList
		vector<movie> getRec();

};

template<typename K, typename V>
std::pair<K,V> getMaximumValue(const std::map<K,V> &map) {
    return *std::max_element(map.begin(), map.end(), [](std::pair<K,V> const &x, std::pair<K,V> const &y) {
        return x.second < y.second;
    });
}


template<typename K >
map<K,int> help_getFreq(vector<K> list){
	map<K,int> freqMap;

	for(auto x : list){
		if(freqMap.find(x) == freqMap.end()){
			freqMap[x] = 1;
		}
		else{
			freqMap[x] ++;
		}
	}
	return freqMap;
	
}

#endif