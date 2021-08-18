#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, C;
	cin >> A >>B;
	if (B==0){
		cout<<"Indefinite";
	}
	else{
		C = A/B;
		cout<<C<<endl;
	}
	

	return 0;
}