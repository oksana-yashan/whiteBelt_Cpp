#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


// void Print(const vector<int>& nums) {
// 	for (auto& n:nums) {
// 		cout <<n<<" ";
// 	}
// }

struct Specialization {
	string value;
	explicit Specialization(string s) {
		value = s;
	}
};

struct Course {
	string value;
	explicit Course( string s) {
		value = s;
	}
};

struct Week {
	string value;
	explicit Week( string s) {
		value = s;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;

	LectureTitle(Specialization s, Course c, Week w) {
		specialization = s.value;
		course = c.value;
		week = w.value;
	}
};

int main() {

	
	LectureTitle title(
	    Specialization("C++"),
	    Course("White belt"),
	    Week("4th")
	);



	return 0;
}