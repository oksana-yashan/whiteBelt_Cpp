#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


map<char, int> AnagramCheck(const string& str) {
	map<char, int> result;
	for (char c:str) {
		++result[c];
	}
	return result;
}



int main(){

	int n;
	cin>>n;

	string first, second;

	for (int i=0; i<n; ++i) {
		cin>>first>>second;
		if (AnagramCheck(first) == AnagramCheck(second)) {
			cout << "YES"<<endl;
		}
		else{
			cout << "NO"<<endl;

		}

	}

	return 0;
}