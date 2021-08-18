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


	if (! filesystem::exists("file1.txt") ){
		ofstream  output("file1.txt");
		output<<0.5<<"\n"<<0.34567<<"\n"<<10.4<<endl;
		output.close();
	}
	
	double  n1 = 0, n2 = 0, n3 = 0;

	ifstream input("file1.txt");
	if (input.is_open()) {
		cout<<fixed<<setprecision(3);

		// while (getline(input, line)){
		// 	cout<<line<<endl;
		// }

		while(input >> n1) {
			input.ignore(1);
			cout<<n1<<endl;
		}
		
	}

	if( remove( "file1.txt" ) != 0 )
    	perror( "Error deleting file" );
    else
    	puts( "File successfully deleted" );
  
		
	return 0;
}