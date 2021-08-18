#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> PalindromFilter (vector<string> s, int min){

	int last_index; 
	bool isWordPalindrom;
	vector<string> filtered;

	for (string word:s){

		isWordPalindrom = true;	
		last_index = word.length()-1;
		for (int i =0; i<word.length()/2; i++){
			if (word[i] != word[last_index-i]){
				isWordPalindrom = false;
			}
		}
		if (isWordPalindrom && word.length() >= min){
			filtered.push_back(word);
		}
	}
		
	return filtered;
}

int main() {

	vector<string> s = {"weew","bro","code","a","aa"};
	int min = 4;
	vector<string> filtered = PalindromFilter(s, min);
	for (auto fil : filtered){
		cout<< fil<<" ";
	}
	
	return 0;
}