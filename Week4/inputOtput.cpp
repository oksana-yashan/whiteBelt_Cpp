#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;


void Print(const vector<int>& nums) {
	for (auto& n:nums) {
		cout <<n<<" ";
	}
}

int main() {

	if (! filesystem::exists("file1.txt") ){
		ofstream  output("file1.txt");
		output<<"Keep calm"<<"\n"<<"and "<<"\n"<<"learn C++"<<endl;
		output.close();
	}
	


	// string line;
	// ifstream input("file1.txt");
	// if (input.is_open()) {
	// 	while (getline(input, line))
	// 		cout<<line<<endl;
	// }
	remove( "file2.txt" );


	string line;
	ifstream input("file1.txt");
	ofstream output2("file2.txt");
	if (input.is_open()) {
		while (getline(input, line)){
			output2<<line<<endl;
		}		}
	}
	input.close();


	ifstream input2("file2.txt");
	if (input2.is_open()) {
		while (getline(input2, line)){
			cout<<line<<endl;
		}
	}

	if( remove( "file1.txt" ) != 0 )
    	perror( "Error deleting file" );
    else
    	puts( "File successfully deleted" );
  
		
	return 0;
}