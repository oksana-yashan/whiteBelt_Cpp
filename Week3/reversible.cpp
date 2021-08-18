#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


void Print(const vector<int>& nums) {
	for (auto& n:nums) {
		cout <<n<<" ";
	}
}

class ReversibleString{
public:

	ReversibleString() {
		str = "";
	}

	ReversibleString(const string& s) {
		str = s;
	}

	void Reverse() {
		// reverse(str.begin(), str.end());
		 char tmp;
		 for (int i=0; i<str.size()/2; ++i) {
		 	tmp = str[i];
		 	str[i] = str[str.size()-1-i];
		 	str[str.size()-1-i] = tmp;
		 }
		
	}
	string ToString() const{
		return str;
		
	}	
	string str;


};

int main() {

	// int n;
	// cin>>n;

	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;
	  
	s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
   
    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;
  


	return 0;
}