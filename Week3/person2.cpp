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
		// string temp_fN, temp_lN = "", "";
		// string history_fN = "";
		// string history_lN = "";


		if (sortedStrings.size() == 0) {
			return "Incognito";
		}
		for (const auto& i : sortedStrings) {
      if (year < i.first) return "Incognito"; //if year<first year in db
        	break; 
    }
		for (const auto& [key, values] : sortedStrings ) {
			if (key <= year) {
					if (values.firstName != "") {
						fN = values.firstName;
						// if (temp_fN != fN) {
						// 	history_fN +=(temp_fN + " ");
						// }						
						// temp_fN = fN;
					}
						
					else if (values.lastName != "") {
						lN = values.lastName;
						// if (temp_lN != lN) {
						// 	history_lN +=(temp_lN + " ");
						// }						
						// temp_lN = lN;
					}
			}
		}
		return fN + " " + lN;
	}



	string GetFullNameWithHistory(int year) {
		string fN, lN;
		string temp_fN = "", temp_lN = "";
		string history_fN = "", history_lN = "";


		if (sortedStrings.size() == 0) {
			return "Incognito";
		}
		for (const auto& i : sortedStrings) {
      if (year < i.first) return "Incognito"; //if year<first year in db
        	break; 
    }
		for (const auto& [key, values] : sortedStrings ) {
			if (key <= year) {
					if (values.firstName != "") {
						fN = values.firstName;
						if (temp_fN != fN && temp_fN != "") {
							history_fN = (history_fN == "") ? temp_fN : temp_fN + ", "+history_fN;
						}						
						temp_fN = fN;
					}
						
					if (values.lastName != "") 
						lN = values.lastName;
						if (temp_lN != lN && temp_lN != "") {
							history_lN = (history_lN == "") ? temp_lN : temp_lN + ", " + history_lN;
						}						
						temp_lN = lN;
			}
		}
		return history_fN != "" ? ( history_lN != "" ? fN+" ("+history_fN+") "+lN+" ("+history_lN+")" : fN+" ("+history_fN+") "+lN ) : 
						( history_lN != "" ? fN+" "+lN+" ("+history_lN+")" : ((fN != "") ? fN+" "+lN : lN));
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

	// Person person;
  
 //  person.ChangeFirstName(1965, "Polina");
 //  person.ChangeLastName(1967, "Sergeeva");
 //  for (int year : {1900, 1965, 1990}) {
 //    cout << person.GetFullName(year) << endl;
 //  }
  
 //  person.ChangeFirstName(1970, "Appolinaria");
 //  for (int year : {1969, 1970}) {
 //    cout << person.GetFullName(year) << endl;
 //  }
  
 //  person.ChangeLastName(1968, "Volkova");
 //  for (int year : {1969, 1970}) {
 //    cout << person.GetFullName(year) << endl;
 //  }

	Person person;

  // person.ChangeFirstName(1900, "Eugene");
  // person.ChangeLastName(1900, "Sokolov");
  // person.ChangeLastName(1910, "Sokolov");
  // person.ChangeFirstName(1920, "Evgeny");
  // person.ChangeLastName(1930, "Sokolov");
  // cout << person.GetFullNameWithHistory(1940) << endl;  










  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;






  // person.ChangeFirstName(1965, "Polina");
  // person.ChangeFirstName(1965, "Appolinaria");

  // person.ChangeLastName(1965, "Sergeeva");
  // person.ChangeLastName(1965, "Volkova");
  // person.ChangeLastName(1965, "Volkova-Sergeeva");

  // for (int year : {1964, 1965, 1966}) {
  //   cout << person.GetFullNameWithHistory(year) << endl;
  // }

  

	return 0;
}