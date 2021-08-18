#include <iostream>
#include <vector>

#include <algorithm>
#include <ctime>	
#include <chrono>

using namespace std;
using namespace std::chrono;


vector<int> Reverse(const vector<int>& v){

	vector<int> reversed(v.size());
	int last_index = v.size()-1;

	for (int i=0; i<v.size(); ++i){
		reversed[i] = v[last_index-i];
	}
	return reversed;
}



vector<int> Reversed(const vector<int>& input)
{
    vector<int> result;
    for (int i = input.size() - 1; i >= 0; --i) {
        result.push_back(input[i]);
    }
    return result;
}



int main(){

	

	srand(unsigned(time(nullptr)));
	vector<int> v(1000);
	generate(v.begin(), v.end(), rand);

	vector<int> reversed;
	//11ms 999000
	auto start = steady_clock::now();
	reversed = Reverse(v);
	auto finish = steady_clock::now();
	cout<<duration_cast<milliseconds>(finish-start).count() <<"ms ";


	reversed.clear();
	//20ms 999000
	start = steady_clock::now();
	reversed = Reversed(v);
	finish = steady_clock::now();
	cout<<duration_cast<milliseconds>(finish-start).count() <<"ms ";

	v.clear();



	// vector<int> numbers = {1, 5, 3, 4, 2};
	// vector<int> reversed;

	// reversed = Reverse(numbers);
	
	// for (auto n:reversed){
	// 	cout<<n<<" ";
	// }





	return 0;
}