#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int a, div;
	vector<int> bin;

	cin >> a;

	if (a == 0){
		bin.push_back(0);
	}
	else{
		while(a!=0) {
			div = a/2;
			bin.push_back(a-div*2);
			a = div;
		}
	}
	for (int i = bin.size()-1; i>=0; --i){
		cout<<bin[i];
	}
	
	return 0;
}
