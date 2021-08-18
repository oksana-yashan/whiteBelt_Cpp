#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


int main(){

	int n, k;
	cin>>n;

	map<string, vector<string>> stop_Buses, bus_Stops;

	string oper;
	string curr_stop, busName;
	int stopCount;



	for (int i=0; i<n; ++i) {
		cin>>oper;
		if (oper == "NEW_BUS") {
			cin>>busName>>k;
			for (int j = 0; j<k; ++j) {
				cin >> curr_stop;
				bus_Stops[busName].push_back(curr_stop);
				stop_Buses[curr_stop].push_back(busName);

			}
		}
		else if (oper == "BUSES_FOR_STOP") {
			cin >> curr_stop;
			if (stop_Buses.count(curr_stop) == 0) {
				cout<<"No stop"<<endl;
			}
			else {
				cout<<"Stop "<<curr_stop<<": ";
				for (const string& bus: stop_Buses[curr_stop]) {
					cout<<bus<<" ";
				}
				cout<<endl;
			}

		}
		else if (oper == "STOPS_FOR_BUS") {
			cin >> busName;
			
			if (bus_Stops.count(busName) == 0) {
				cout<<"No bus"<<endl;
			}
			else {
				for (const string& stop: bus_Stops[busName]) {
					int counter = 0;
					cout<<"Stop "<<stop<<": ";
					for (const string& bus : stop_Buses[stop]) {
						if (bus != busName) {
							cout << bus<< " ";
							++counter;
						}
					}
					if (counter == 0) {
						cout << "no interchange ";
					}
					cout<<endl;
				}
			}

		}
		else if (oper == "ALL_BUSES") {
			if (bus_Stops.size() == 0) {
				cout<<"No buses"<<endl;
			}
			else {
				for (const auto [bus, stops] : bus_Stops) {
					cout<<"Bus "<<bus<<": ";
					for (const string& stop : stops) {
						cout << stop<< " ";						
					}
					cout<<endl;
				}
			}
			

		}

	}

	return 0;
}