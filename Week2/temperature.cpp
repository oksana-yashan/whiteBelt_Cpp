#include <iostream>
#include <vector>

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
	
	int average = 0;
	vector<int> temperature(n);

	// for (int i=0; i<temperature.size(); ++i){
	// 	cin>>temperature[i];
	// 	average+=temperature[i]; 
	// }

	for (int& t : temperature) {
	    cin >> t;
	    average += t;
    }

	average/=n;
	cout<<average<<endl;

	// PrintVectorGtThanAverage(temperature, average);
	PrintVectorGtThanAverage2(temperature, average,n);
	

	return 0;
}