#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


struct Student
{
	string name;
	string surname;
	int bDay;
	int bMonth;
	int bYear;
};




void Print(const vector<int>& nums) {
	for (auto& n:nums) {
		cout <<n<<" ";
	}
}

void PrintName(const vector<Student>& students, int i) {
	Student student = students[i];
	cout<<student.name<<" "<<student.surname<<endl;
}

void PrintDate(const vector<Student>& students, int i) {
	Student student = students[i];
	cout<<student.bDay<<"."<<student.bMonth<<"."<<student.bYear<<endl;
}



int main() {

	int n;
	cin>>n;

	string name, surname;
	int bDay,bMonth, bYear;

	vector<Student> students;


	for (int i=0; i<n; ++i ){
		cin >> name >> surname >> bDay >> bMonth >> bYear;
		students.push_back( Student{name, surname, bDay, bMonth, bYear});
	}



	// requests for student output

	cin>>n;
	string oper;
	int index;
	for (int i = 0; i<n; ++i ) {
		cin >> oper>>index;

		if (oper == "name" && index >= 0 && index<=students.size()) {
			PrintName(students, --index);
		}
		else if (oper == "date"&& index >= 0 && index<=students.size()) {
			PrintDate(students, --index);
		}
		else {
			cout<<"bad request"<<endl;
		}


	}



	return 0;
}