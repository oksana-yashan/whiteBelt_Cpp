#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


class SortedStrings {

public:

	int BinarySearch(const string& s) {
		int size = sortedStrings.size();
		int index = 0;

		if (size != 0) {
				if ( sortedStrings[size/2] >= s ){
						for (int i=0; i<=size/2; ++i) {
								if (sortedStrings[i] < s ){
									++index;
								}
								else {
									return index;
								}
						}
				}
				else {
					index = size-1;
					for (int i = size-1; i>=size/2; --i) {
						if (sortedStrings[i] > s ){
									--index;
								}
						else {
							return ++index;
						}
					}
				}

		}
		return 0;
	}

	void AddString(const string& s) {
		// sortedStrings.push_back(s);
		int index = BinarySearch(s);
		sortedStrings.insert(sortedStrings.begin()+index, s);
	
	}

	vector<string> GetSortedStrings(){
		// sort(begin(sortedStrings), end(sortedStrings));
		return sortedStrings;
	}

private:
	vector<string> sortedStrings;
};


void PrintSortedStrings( SortedStrings& ss) {
	for (const string& s : ss.GetSortedStrings()) {
		cout <<s<<" ";
	}
	cout<<endl;
}



int main() {

  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  strings.AddString("third");
  PrintSortedStrings(strings);
  strings.AddString("first1");
  strings.AddString("third3");

  PrintSortedStrings(strings);
  
  strings.AddString("second2");
  PrintSortedStrings(strings);
  

	return 0;
}