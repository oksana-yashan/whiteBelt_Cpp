#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double N, A, B, X, Y;
	double Res;

	cin >> N>>A>>B>>X>>Y;


	if (N > B){
		Res = N * (100.0-Y)/100.0;
	}
	else if (N > A){
		Res = N * (100.0-X)/100.0;
	}
	else{
		Res = N;
	}

	
	cout<<fixed <<Res;
	return 0;
}