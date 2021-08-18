#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <ctype.h>

using namespace std;


void Print(const vector<string>& nums) {
	for (auto& n:nums) {
		cout <<n<<" ";
	}
}

int main() {

	int n;
	string str1;
	vector<string> str;

	cin>>n;

	for (int i = 0; i<n; ++i) {
		cin>>str1;
		str.push_back(str1);
	}

	sort(begin(str), end(str), [](string& i, string& j){
		string result1, result2;
		for (auto& el:i) { result1 += tolower(el); }
		for (auto& el:j) { result2 += tolower(el); }
		return result1<result2;
	});
	Print(str);

	return 0;
}