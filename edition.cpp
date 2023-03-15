#include "edition.h"
using namespace std;

edition::~edition() {

	name = "";
	audience = nullptr;
	founder = "";
	price = 0;
	circulation = 0;
	view = "";
}

bool edition::operator==(const edition& p) {
	return name == p.name &&  view == p.view && circulation == p.circulation && price == p.price && audience == p.audience && founder == p.founder;
}

edition::edition(const edition& p) {
	length = p.length;
	if (audience != nullptr)
		delete audience;
	audience = new char[length + 1];
	strcpy(audience, p.audience);
	audience[length] = 0;
	name = p.name;
	founder = p.founder;
	price = p.price;
	circulation = p.circulation;
	view = p.view;
}

edition::edition() {
	name = "";
	audience = nullptr;
	founder = "";
	price = 0;
	circulation = 0;
	view = "";
}

edition::edition(string name1, string view1, int circulation1, int price1, const char *audience1, string founder1) {
	length = strlen(audience1);
	audience = new char[length + 1];
	name = name1;
	strcpy(this->audience, audience1);
	audience[length] = 0;
	founder = founder1;
	price = price1;
	circulation = circulation1;
	view = view1;
	founder = founder1;
}

edition& edition::operator=(const edition& p) {
	if (this == &p)
		return *this;
	length = p.length;
	if (audience != nullptr)
		delete audience;
	audience = new char[length + 1];
	strcpy(audience, p.audience);
	audience[length] = 0;
	name = p.name;
	founder = p.founder;
	price = p.price;
	circulation = p.circulation;
	view = p.view;
	founder = p.founder;

}

istream& operator>>(istream& str, edition& p) {
	string name1;
	string view1;
	string founder1;
	int price1;
	int circulation1;
	string audience1;
	getline(str, name1, ' ');
	getline(str, view1, ' ');
	str >> price1 >> circulation1;
	getline(str, audience1, ' ');
	getline(str, founder1, '\n');
	p = edition(name1, view1, price1, circulation1, audience1.c_str(), founder1);
	return str;
}

ostream& operator<<(std::ostream& str, edition& p) {
	str << p.name << ' ' << p.view << ' ' << p.circulation << ' ' << p.price << ' ' << p.audience << ' ' << p.founder << endl;
	return str;
}

bool edition::operator<(const edition& p) {
	if (circulation < p.circulation)
		return true;
	else if (circulation == p.circulation)
		if (founder < p.founder)
			return true;
		else if (founder == p.founder)
			if (view < p.view)
				return true;

	return false;
}

bool edition::operator>(const edition& p) {
	if (circulation > p.circulation)
		return true;
	else if (circulation == p.circulation)
		if (founder > p.founder)
			return true;
		else if (founder == p.founder)
			if (view > p.view)
				return true;

	return false;
}

string edition::GetName() {
	return name;
}

int edition::GetPrice() {
	return price;
}

edition &edition::operator%(int value) {
	double c = value % 100;
	circulation = circulation * (1 + (c / 100));
	return *this;
}

edition &edition::operator-(int value) {
	price = price - value;
	return *this;
}