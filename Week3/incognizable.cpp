
#include <iostream>
#include <string>

using namespace std;

struct Incognizable {
	int x = 0;
	int y = 0;
};

class Incogn {
public:
	Incogn(int xi, int yi) {
		x= xi;
		y= yi;
	}

	~Incogn() {
		cout<<"Destructor";
	}

	void PrintRoute(const Route& r){
		;
	}

	int x, y;
};


int main() {
  Incognizable a;
  Incognizable b({});
  Incognizable c({0});
  Incognizable d ({0, 1});

  cout<<d.x<<" "<<d.y<<"\n";


  Incogn inc ({100,200});
  Incogn inc2(100, 200);
  cout<<inc.x<<inc.y<<endl;

  PrintRoute(Route());
  PrintRoute({});

  PrintRoute(Route("100", "200"));
  PrintRoute({"100", "200"});

  return 0;
}