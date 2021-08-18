#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

void PrintVector(const vector<int>& v){
	for (int i=0; i<v.size(); i++){
		cout<<v[i]<<"  ";
	}
	
}




int main(){
	
	int n;
	cin>>n;

	/*
	"ADD"
	"NEXT"
	"DUMP"
	*/

	vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
	int curr_month = 0;
	int delta;

	vector<vector<string>> routine(days[curr_month]);


	string oper, task;
	int prev_n, curr_n, day;
	int curr_days;
	// curr_n = 0;

	for (int i = 0; i<n; ++i){
		cin>>oper;
		if (oper == "ADD"){
				cin>>day;
				cin>>task;

				routine[day-1].push_back(task);
		}
		else if (oper == "NEXT"){
			curr_month = (curr_month == 11) ? 0 : curr_month+1;
			// if (curr_month == 11) {
			// 	curr_month = 0;
			// }
			// else {
			// 	++curr_month;
			// }

			int prev = curr_month-1;
			delta = days[prev] - days[curr_month];
			// cout <<days[prev]<<" "<<days[curr_month]<<endl;
			// cout<<"delta"<<delta<<" ";

			if (delta < 0) {
					routine.resize(days[curr_month]);
			}
			else if (delta > 0) {

					for (int i = 0; i<delta; ++i) {
							curr_days = days[curr_month];

							if ( routine[curr_days+i].size() != 0) {
									// cout<< "check"<<routine[curr_days+i][0]<<endl;
									routine[ curr_days -1].insert(end(routine[ curr_days-1 ]),
										begin(routine[curr_days+i]), end(routine[curr_days+i]));
									routine[curr_days+i].clear();
							}
					}
			}
			//else delta = 0 => do nothing;


		}
		else if (oper == "DUMP"){
				cin>>day;
				cout<<routine[day-1].size()<<" ";
				for (string t:routine[day-1]) {
					cout<<t<<" ";
				}
				cout<<" "<<endl;
		}
	}


	return 0;
}