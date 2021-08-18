

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <tuple>

using namespace std;

class Data{
public:

	Data(int y, int m, int d) {
		// if (y == "" || m =="" | d == "") {
		// 	throw invalid_argument("Data argument can`t be empty");
		// }
		if (y>=0 && y<2021) {
			year = y;
		} else {
			throw invalid_argument("Year value is invalid: "+ to_string(y));
		}

		if (m>0 && m<13) {
			month =m;
		} else {
			throw invalid_argument("Month value is invalid: "+ to_string(m));
		}

		if (d>=0 && d<32) {
			day = d;
		} else {
			throw invalid_argument("Day value is invalid: "+ to_string(d));
		}
	}

	int Year() const {
		return year;
	}

	int Month() const {
		return month;
	}

	int Day() const {
		return day;
	}

private:
	int day;
	int month;
	int year;
};




bool operator < (const Data& d1, const Data& d2) {
		// if (d1.Year() < d2.Year()) {
		// 	return true;
		// }
		// else if (d1.Year() > d2.Year()) {
		// 	return false;
		// }
		// else {
		// 	if (d1.Month() < d2.Month()) {
		// 		return true;
		// 	}
		// 	else if (d1.Month() > d2.Month()) {
		// 		return false;
		// 	}
		// 	else {
		// 		if (d1.Day() < d2.Day()) {
		// 			return true;
		// 		}
		// 		else if (d1.Day() > d2.Day()) {
		// 			return false;
		// 		}
		// 		else{
		// 			return false;
		// 		}
		// 	}
		// }



		// if (d1.Year() != d2.Year()) {
		// 	return d1.Year() < d2.Year();
		// }
		// if (d1.Month() != d2.Month()) {
		// 	return d1.Month() < d2.Month();
		// }
		// return d1.Day() < d2.Day();



		auto l = tie(d1.Year(), d1.Month(), d1.Day());
		auto r = tie(d2.Year(), d2.Month(), d2.Day());
		return l<r;


	}



ostream& operator<<(ostream& stream, const Data& d) {
	stream<<setw(4)<<setfill('0')<<d.Year()<<"-"
	<<setw(2)<<setfill('0')<<d.Month()<<"-"
	<<setw(2)<<setfill('0')<<d.Day()<<" ";
	return stream;
}




class Database {

public:
	void Add(Data& data, string event) {
		db[data].insert(event);
	}

	void Del(Data& data, string event) {
		try {
			if (event != "") {
				if (db.count(data) > 0) {
					set<string> ev;
					ev = db.at(data);
					int n = db.at(data).erase(event);
					if (n != 0){
						cout<<event<<endl;
						cout<<"Deleted successfully";
					}
					else{
						cout<<"Event not found";
					}
					

					// for (const string& e: ev){
					// 	if (e == event){
					// 		db.at(data).erase(e);
					// 		cout<<"Deleted successfully";
					// 		break;
					// 	}
					// }

					
				}
				else {
					cout<<"Event not found";
				}
			}
			else {

				if (db.count(data) > 0) {
					set<string> ev;
					ev = db.at(data);
					int size = db.at(data).size();
					db.at(data).clear();
					cout<<"Deleted "+to_string(size)+" events";
				
				}
			}
		} catch(exception e) {
			cout<<"Event not found";
		}
		
	}

	set<string> Find(Data& data) {
		if (db.count(data) > 0){
			return db.at(data);
		}
		else {
			return {};
		}
		
	}

	void Print() const {
		for (const auto& db_i: db){
			for (const string& e: db_i.second){
				cout<<db_i.first<<" "<<e<<endl;
			}
		}
		
	}

private:
	map<Data, set<string>> db;
};





int main() {

	Database db;
	string input, oper;
	
	char c;

	while (getline(cin, input)) {
		// cout<<input;
		stringstream ss (input);
		ss>>oper;
		string date, event;

		if (oper == "Add") {
			ss>>date>>event;
			int day, month, year;
			stringstream dmy(date);
			dmy>>year>>c>>month>>c>>day;
			// cout<<year<<" "<<month<<" "<<day;

			Data d(year, month, day);
			db.Add(d, event);
			// cout<<endl;


		}
		else if (oper == "Del") {
			ss>>date>>event;
			int day, month, year;
			stringstream dmy(date);
			dmy>>year>>c>>month>>c>>day;
			Data d(year, month, day);

			db.Del(d, event);
			cout<<endl;

		}
		else if (oper == "Find") {
			ss>>date;
			int day, month, year;
			stringstream dmy(date);
			dmy>>year>>c>>month>>c>>day;
			Data d(year, month, day);

			set<string> s = db.Find(d);
			for (const string& ss:s) {
				cout<<ss<<endl;
			}

		}
		else if (oper == "Print") {
			db.Print();
		}
		else {
			// throw logic_error("Unknown command: "+oper);
			cout<<"Unknown command: "+oper<<endl;
		}

	}

	return 0;
}