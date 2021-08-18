#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


class Name {
public:
	string firstName = "";
	string lastName = "";
};

class Person {

public:
	void ChangeFirstName(int year, const string& firstName) {
		// if (sortedStrings.count(year) == 0)
		// 	sortedStrings[year].lastName = "";
		sortedStrings[year].firstName = firstName;
	}

	void ChangeLastName(int year, const string& lastName) {
		// if (sortedStrings.size() == 0)
		// 	sortedStrings[year].firstName = "";
		sortedStrings[year].lastName = lastName;
	}

	string GetFullName(int year) {
		string fN, lN;

		if (sortedStrings.size() == 0) {
			return "Incognito";
		}
		for (const auto& i : sortedStrings) {
      if (year < i.first) return "Incognito"; //if year<first year in db
        	break; 
    }
		for (const auto& [key, values] : sortedStrings ) {
			if (key <= year) {
					if (values.firstName != "") 
						fN = values.firstName;
					else if (values.lastName != "") 
						lN = values.lastName;
			}
		}
		return fN + " " + lN;
	}

private:
	map<int, Name> sortedStrings;

};



// void PrintSortedStrings( SortedStrings& ss) {
// 	for (const string& s : ss.GetSortedStrings()) {
// 		cout <<s<<" ";
// 	}
// 	cout<<endl;
// }



int main() {

	Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  

	return 0;
}