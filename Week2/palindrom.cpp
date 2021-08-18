#include <iostream>
#include <string>
using namespace std;


bool Palindrom (string s){

	int last_index = s.length()-1;
	for (int i =0; i<s.length()/2; i++){
		if (s[i] != s[last_index-i]){
			return false;
		}
	}
	return true;
}

int main() {

	string s;
	cin>>s;
	cout<< Palindrom(s);
	return 0;
}