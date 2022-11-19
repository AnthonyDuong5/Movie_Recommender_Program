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

		vector<movie> TrackViewList;
		
		int prompt = 0;

		//adding a movieList,can use funcions from the movieList if needed.
		movieList userFavList;

	public:
		User();
		vector<movie> ReturnTrackList (){return TrackViewList;}
		void AddToTrackList(const movie& );
		void AddToFavoriteList(const movie& m1);
		vector <movie>& getFavoritesList(){ return Favorites;}
		vector<movie> getDefaultList(){return DefaultList;}
		vector<movie> getViewingList(){return ViewingList;}
		
		// vector<movie> getPrintedList(){return PrintedList;}
		void removeFromViewingList(unsigned idx);

		vector<movie> getRec();
		
};



//help_getFreq takes a vector of K type and returns 
//a map with the frequency of each element in the vector
//(key : value) = (element : frequency)
template<typename K>
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
//help_getMaximumValue returns the highest value(frequenct) pair from a map
template<typename K, typename V>
pair<K,V> help_getMaximumValue(const map<K,V> &map) {
    return *std::max_element(map.begin(), map.end(), [](pair<K,V> const &x, pair<K,V> const &y) {
        return x.second < y.second;
    });
}
#endif