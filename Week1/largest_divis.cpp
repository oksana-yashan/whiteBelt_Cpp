#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int a,b;
	int largest = 1;

	cin >> a>>b;


	for (int i = 2; i<=min(a, b); ++i){
		if (a%i==0 && b%i ==0){
			largest = i;
		}
	}
	
	cout<<largest;
	return 0;
}