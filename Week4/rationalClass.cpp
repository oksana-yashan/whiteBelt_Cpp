#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include <map>

using namespace std;


class Rational {
public:
	Rational(){
		numerator = 0;
		denominator = 1;
	}
	Rational( int n,  int d) {

		if (n == 0) {
			// Rational();   //error but i don`t know why((
			numerator = 0;
			denominator = 1;
		}

        else if( d == 0 ){
            throw invalid_argument("Invalid argument");
        }

		else {
			if ((n <0 && d<0) || (n >=0 && d<0)) {
				n = -n; 
				d = -d;
			}

			gcd = gcd_func(abs(n), abs(d));
	    	if (gcd != 1) {
	    		n /= gcd;
	    		d /= gcd;
	    		gcd = 1;
	    	}
			numerator = n;
			denominator = d;

		}
		
	}

    int Numerator() const {
    	return numerator;
    }
    
    int Denominator() const {
    	return denominator;
    }



private:
	int numerator;
	int denominator;
	int gcd;

	int gcd_func(int f, int s) {
		while (f >0 && s >0) {
			if (f>s) {
				f = f%s;
			}
			else if (s>f) {
				s = s%f;			}
		}
		return s+f;
	}
};

bool operator==(const Rational& l, const Rational& r) {
	if ((l.Numerator() == r.Numerator()) && (l.Denominator() == r.Denominator() )) {
		return true;
	}
	return false;
}


Rational operator+( Rational& l, Rational& r) {

	int res_den = l.Denominator() * r.Denominator();
	int n1 = l.Numerator() * (res_den/l.Denominator());
	int n2 = r.Numerator() * (res_den/r.Denominator());

	Rational res(n1+n2, res_den);
	return res;
}


Rational operator-( Rational& l, Rational& r) {

	int res_den = l.Denominator() * r.Denominator();
	int n1 = l.Numerator() * (res_den/l.Denominator());
	int n2 = r.Numerator() * (res_den/r.Denominator());

	Rational res(n1-n2, res_den);
	return res;
}

Rational operator*(Rational& l, Rational& r) {
	int res_n, res_d;
	res_n = l.Numerator() * r.Numerator();
	res_d = l.Denominator() * r.Denominator();

	Rational res(res_n, res_d);
	return res;
}

Rational operator/(const Rational& l, const Rational& r) {
	int res_n, res_d;
	res_n = l.Numerator() * r.Denominator();
	res_d = l.Denominator() * r.Numerator();

    if (res_d == 0) {
        throw domain_error("Division by zero");
    }

	Rational res(res_n, res_d);
	return res;
}


istream& operator >> (istream& istr, Rational& r) {

	//input1("1*2"), input2("1/"), input3("/4");

	int n = 0, d = 0;
    char c = istr.peek();
    istr >> n;

    // if (isdigit(c) || c == '-' || c == ' ') {
    //     istr>>n;
    // }
    // else {
    //     throw invalid_argument("No numerator was given");
    // }
	
	
	istr.get(c);
	if ((c != '/') ){
        // throw invalid_argument("Wrong deliminator");
		return istr;
	}

	istr>>d;
    // if ( n!= 0 && d != 0) {
	if ( true ) {
		r = Rational(n, d);
	}
	return istr;
}




ostream& operator << (ostream& ostr, const Rational& r) {

	ostr << r.Numerator()<<'/'<<r.Denominator();
	return ostr;
}

// bool operator > (Rational a, Rational b) {
//     return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
// }
bool operator < (Rational a, Rational b) { //for using map & set
    return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}


int main() {

	 {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 6;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 7;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 8;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 9;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 10;
        }
    }

    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        try {
            istringstream input1("1*2"), input2("1/"), input3("/4");
            Rational r1, r2, r3;
            input1 >> r1;
            input2 >> r2;
            input3 >> r3;
            bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
            if (!correct) {
                cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                     << r1 << " " << r2 << " " << r3 << endl;

                return 6;
            }
        } catch (invalid_argument& e){}
    }


    {
        const set<Rational> rs = { { 1, 2 },{ 1, 25 },{ 3, 4 },{ 3, 4 },{ 1, 2 } };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }
 
        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }
 
    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];
 
        ++count[{2, 3}];
 
        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

     try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }


    cout << "OK" << endl;






    //calculator
    int n, d;
    char oper;

    Rational r1, r2;


    try {
    cin >> r1 >>oper>> r2;
    // cout<<r1<<"    "<<oper<<"   "<<r2;
    cout<<r2.Numerator()<<r2.Denominator();

    
        if (oper == '+') {
            cout<<r1+r2;
        }
        else if (oper == '-') {
            cout<<r1-r2;
        }
        else if (oper == '*') {
            cout<<r1*r2;
        }
        else if (oper == '/') {
            cout<<r1/r2;
        }
    } catch (exception& e) {
        cout<<e.what();
    }

    


	return 0;
}