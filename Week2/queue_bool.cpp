#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVector(const vector<int>& v){
	for (int i=0; i<v.size(); i++){
		cout<<v[i]<<"  ";
	}
	
}



int main(){
	
	int n;
	cin>>n;

	//come positive and negative
	/*"COME"
	"WORRY"
	"QUIET"
	"WORRY_COUNT"
	*/

	string oper;
	vector<bool> worry_indexes;
	int prev_n, curr_n, delta;
	curr_n = 0;



	for (int i = 0; i<n; ++i){
		cin>>oper;
		if (oper == "COME"){
				cin>>delta;
				curr_n += delta;
				worry_indexes.resize(curr_n);
				
		}
		else if (oper == "WORRY"){
				cin>>delta;
				worry_indexes[delta] = true;
		}
		else if (oper == "WORRY_COUNT") {
			int counter = 0;
				for (bool el:worry_indexes) {
						if (el == 1) {
							++counter;
						}
				}
			cout<<counter<<endl;
		}
		else if (oper == "QUIET"){
				cin>>delta;
				worry_indexes[delta] = false;
		}
	}


	return 0;
}