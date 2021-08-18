#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	double d, x1, x2;
	cin>>a>>b>>c;

	// cout <<a<<" "<<b<<" "<<c;
	//bx+c = 0
	if (a==0){
		if (b !=0 ){
			cout<<-c/b;	
		}
	}
	else{
		d = b*b-4*a*c;
		x1 = (-b-sqrt(d))/2*a;
		x2 = (-b+sqrt(d))/2*a;
		cout<<x1<<" "<<x2;
	}

	return 0;
}