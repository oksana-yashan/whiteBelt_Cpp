#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <filesystem>
#include <iomanip>

using namespace std;


void Print(const vector<int>& nums) {
	for (auto& n:nums) {
		cout <<n<<" ";
	}
}

int main() {


	int width = 10;

	int  num;
	int n, m;



	string lines;


	ifstream input("input.txt");
	if (input.is_open()) {

		input>>n;
		input.ignore(1);
		input>>m;
		input.ignore(1);


		cout<<setw(width);
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m-1; ++j){
				input>>num;
				input.ignore(1);

				cout<<setw(width)<<num<<" ";
			}
			input>>num;
			input.ignore(1);
			cout<<setw(width)<<num<<endl;;
		}

		// for (int i = n; i > 0;--i) {
  //       for (int z = m; z > 1; --z) {
  //           getline(input, lines, ',');
  //           cout << setw(10) << lines << " ";
  //       }
  //       getline(input, lines);
  //       cout << setw(10) << lines << endl;
  // }

	}
		
	return 0;
}