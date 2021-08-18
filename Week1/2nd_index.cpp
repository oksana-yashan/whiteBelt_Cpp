#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	string string1;
	int index;
	int counter = 0;

	cin >> string1;


	for (int i =0; i<string1.size(); ++i){
		if (string1[i] == 'f'){
			++counter;
			index = i;
		}

	}
	if (counter ==1){
		index = -1;
	}
	else if (counter ==0){
		index = -2;
	}
	

	
	cout<<index;
	return 0;
}