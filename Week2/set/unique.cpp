#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {

	int n;
	cin>>n;

	set<string> unique;
	string value;

	for (int i=0; i<n; ++i) {
		cin>>value;
		unique.insert(value);
	}

	cout<<unique.size()<<endl;
	return 0;
}