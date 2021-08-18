#include <iostream>
#include <vector>

using namespace std;


void Reverse(vector<int>& v){
	int last_index = v.size()-1;
	int temp;
	for (int i=0; i<v.size()/2; ++i){
		temp = v[i];
		v[i] = v[last_index-i];
		v[last_index-i] = temp;
	}
}

int main(){

	vector<int> numbers = {1, 5, 3, 4, 2};
	Reverse(numbers);
	
	for (auto n:numbers){
		cout<<n<<" ";
	}

	return 0;
}