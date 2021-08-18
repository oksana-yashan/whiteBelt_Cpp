#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

int main() {

	map<string, set<string>> vocab;

	int n;
	string oper;
	string word1, word2;


	cin>>n;
	for (int i=0; i<n; ++i) {
		cin>>oper;
		if (oper == "ADD") {
			cin>>word1>>word2;
			vocab[word1].insert(word2);
			vocab[word2].insert(word1);

		}
		else if (oper == "COUNT") {
			cin>>word1;
			cout<<vocab[word1].size()<<endl;
		}
		else if (oper == "CHECK") {
			cin>>word1>>word2;
			// bool is = false;
			set<string> synon = vocab[word1];

			string is = synon.count(word2)>0 ? "YES":"NO";


			// for (const auto& word: synon) {
			// 	if ( word == word2 ) {
			// 		cout<<"YES"<<endl;
			// 		is = true;
			// 	}
			// }
			// if ( is == false) {
			// 	cout<<"NO"<<endl;
			// }

			cout<<is<<endl;
		}
	}
	
	return 0;
}