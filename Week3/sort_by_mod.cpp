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

	int n, number;
	vector<int> nums;

	cin>>n;

	for (int i = 0; i<n; ++i) {
		cin>>number;
		nums.push_back(number);
	}

	sort(begin(nums), end(nums), [](int i, int j){return abs(i)<abs(j);});
	Print(nums);
	return 0;
}