#include <iostream>
#include <vector>

using namespace std;

void PrintVector(const vector<int>& v){
	for (int i=0; i<v.size(); i++){
		cout<<v[i]<<"  ";
	}
	
}

int main(){

	vector<int> numbers = {1, 5, 3, 4, 2};
	PrintVector(numbers);
	
	numbers.assign(0, 8);
	PrintVector(numbers);

	

	return 0;
}