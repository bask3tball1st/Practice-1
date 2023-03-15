#include <iostream>
#include <string>
using namespace std;

class edition {
	string name; 
	string view;
	int length = 0;
	int circulation;
	int price;
	char *audience;
	string founder;

public:
	edition();//default
	edition(string name1, string view1, int circulation1, int price1, const char *audience1, string found1);//with parameters
	edition(const edition&);//copy

	friend std::istream& operator>>(istream&, edition&);
	friend std::ostream& operator<<(std::ostream&, edition&);

	bool operator==(const edition&);
	edition& operator=(const edition& p);
	bool operator<(const edition&);
	bool operator>(const edition&);
	edition &operator%(int);
	edition &operator-(int);

	string GetName();
	int GetPrice();

	~edition();
};
