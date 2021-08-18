#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


void Print(const vector<int>& nums) {
	for (auto& n:nums) {
		cout <<n<<" ";
	}
}

int main() {

	// int n;
	// cin>>n;

	vector<int> v;
	Print(v);
	v.insert(v.begin()+1, 2);
	Print(v);



	return 0;
}