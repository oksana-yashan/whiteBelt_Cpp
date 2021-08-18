#include <iostream>
#include <string>
#include <vector>

using namespace std;


void MoveStrings(vector<string>& s1, vector<string>& s2){
	for (string s:s1){
		s2.push_back(s);
	}
	s1.clear();
}

int main(){

	vector<string> source = {"a", "b", "c"};
	vector<string> destination = {"z"};
	MoveStrings(source, destination);
	
	for (auto s:source){
		cout<<s<<" ";
	}
	for (auto s:destination){
		cout<<s<<" ";
	}

	return 0;
}