#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


int main(){

	int n, k;
	cin>>n;

	map<vector<string>, int> route_Bus;

	string curr_stop;
	int counter = 1;
	vector<string> temp_route;



	for (int i=0; i<n; ++i) {
		cin>>k;

		for (int j = 0; j<k; ++j) {
			cin>>curr_stop;
			temp_route.push_back(curr_stop);
		}
		
		for(auto r:temp_route) {
			cout <<r<<endl;
		}

		if (route_Bus.count(temp_route) == 0) {
			route_Bus[temp_route] = counter;
			cout<<"New bus "<<counter<<endl;
			++counter;
		}
		else {
			cout<<"Already exists for "<<route_Bus[temp_route]<<endl;
		}
		temp_route.clear();
	}

	return 0;
}