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


void PrintVectorGtThanAverage(vector<int>& v, int average){
	int counter = 0;

	for (int i=0; i<v.size(); i++){
		if (v[i] > average){
			++counter;
		}
	}

	cout <<counter<<endl;
	for (int i=0; i<v.size(); i++){
		if (v[i] > average){
			cout<<i<<" ";
		}
	}
	
}



void PrintVectorGtThanAverage2(vector<int>& v, int average, int n){

	vector<int> result_indices;
	for (int i = 0; i < n; ++i) {
	  if (v[i] > average) {
	    result_indices.push_back(i);
	  }
	}

    cout << result_indices.size() << endl;
    for (int result_index : result_indices) {
      cout << result_index << " ";
    }
    cout << endl;
	
}


int main(){
	
	int n;
	cin>>n;

	//come positive and negative
	/*"COME"
	"WORRY"
	"QUIET"
	"WORRY_COUNT"
	*/

	string oper;
	vector<int> worry_indexes;
	int prev_n, curr_n, delta;
	curr_n = 0;



	for (int i = 0; i<n; ++i){
		cin>>oper;
		if (oper == "COME"){
				cin>>delta;
				prev_n = curr_n;
				curr_n += delta;
				if (delta<0){
					// cout<<"before remove "<<worry_indexes.size()<<endl;
					for (int j=curr_n; j<prev_n; ++j){
							worry_indexes.erase(remove(worry_indexes.begin(),worry_indexes.end(), j), worry_indexes.end());
							// cout<<"after remove "<<j<<" size: "<<worry_indexes.size()<<endl;
							// PrintVector(worry_indexes);
					}
				}
		}
		else if (oper == "WORRY"){
				cin>>delta;
				worry_indexes.push_back(delta);
		}
		else if (oper == "WORRY_COUNT"){
				cout<<worry_indexes.size()<<endl;
		}
		else if (oper == "QUIET"){
				cin>>delta;
				worry_indexes.erase(remove(worry_indexes.begin(),worry_indexes.end(), delta), worry_indexes.end());
		}
	}


	return 0;
}