#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


map<char, int> AnagramCheck(const string& str) {
	map<char, int> result;
	for (char c:str) {
		++result[c];
	}
	return result;
}



int main(){

	int n;
	cin>>n;

	map<string, string> countryCapital;
	string oper;
	string capital, country;
	string oldCountry, newCountry;



	for (int i=0; i<n; ++i) {
		cin>>oper;
		if (oper == "CHANGE_CAPITAL") {
			cin>>country>>capital;
			if (countryCapital.count(country) == 0) {
				countryCapital[country] = capital;
				cout<<"Introduce new country "<<country<<"with capital "<<capital<<endl;
			}
			else {
				if (countryCapital[country] == capital) {
					cout<<"Country "<<country<<"hasnt changed its capital from "<<capital<<endl;
				}
				else {
					cout<<"Country "<<country<<"has changed its capital from "<<countryCapital[country]<<"to "<<capital<<endl;
					countryCapital[country] = capital;
				}
			}
		}
		else if (oper == "RENAME") {
			cin >> oldCountry >> newCountry;
			if (countryCapital.count(oldCountry) == 0 || countryCapital.count(newCountry) != 0 
					|| oldCountry == newCountry) {
				cout<<"Incorrect rename, skip"<<endl;
			}
			else {
				
				countryCapital[newCountry] = countryCapital[oldCountry];
				countryCapital.erase(oldCountry);
				cout<<"Country "<<oldCountry<<"with capital "<<countryCapital[newCountry]<<"has been renamed to "<<newCountry<<endl;
			}

		}
		else if (oper == "ABOUT") {
			cin >>country;
			if (countryCapital.count(country) == 0) {
				cout<<"Country "<<country<<"doesnt exist"<<endl;
			}
			else {
				cout<<"Country "<<country<<"has capital "<<countryCapital[country]<<endl;			
			}

		}
		else if (oper == "DUMP") {
			if (countryCapital.empty()) {
				cout<<"There are no countries in the world"<<endl;
			}
			else {
				for (const auto& [key, value] : countryCapital ) {
					cout<<key<<"/"<<value<<" ";
				}	
			}

		}

	}

	return 0;
}