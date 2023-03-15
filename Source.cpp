#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include "edition.h"
#include <locale.h>

using namespace std;
ifstream read("input.txt");
edition* LoadDateBase(int& n) {
	if (!read.is_open())
		throw "File is not open!";
	edition *p = new edition[n];
	for (int i = 0; i < n; i++)
		read >> p[i];
	return p;
}

template<typename T>
void Sort(T *p, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (p[j] > p[j + 1])
				swap(p[j], p[j + 1]);
}


void PrintMenu() {
	system("cls");
	cout << "1. Sort the array" << endl;
	cout << "2. Print the array" << endl;
	cout << "3. Increase in circulation " << endl;
	cout << "4. Price reduction " << endl;
	cout << "5. Exit" << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	read >> n;
	read.get();
	edition* p = nullptr;
	p = LoadDateBase(n);
	if (p == nullptr)
		return 0;
	{ cout << "The data has been uploaded successfully." << endl; system("pause"); }

	int choice;
	do {
		PrintMenu();
		cin >> choice;
		switch (choice) {
		case 1:
		{
			Sort(p, n);
			cout << "Sorting was successful!" << endl;
			system("pause");
			break;
		}
		case 2:
		{
			for (int i = 0; i < n; i++)
				cout << p[i] << endl;
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Enter the publisher:" << endl;
			string name2;
			cin >> name2;
			bool proof = false;
			for (int i = 0; i < n; i++) {
				if (name2 == p[i].GetName()) {
					cout << "How many percent do you want to increase the circulation?" << endl;
					int percent;
					cin >> percent;
					p[i].operator%(percent);
					cout << "Circulation has been successfully increased!" << endl;
					proof = true;
				}
			}
			if (!proof) cout << "Nothing found!" << endl;
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Enter the publisher:" << endl;
			string name3;
			cin >> name3;
			bool proof = false;
			for (int i = 0; i < n; i++) {
				if (name3 == p[i].GetName()) {
					cout << "How much do you want to reduce the price?" << endl;
					int percent;
					cin >> percent;
					p[i].operator-(percent);
					cout << "The price has been successfully reduced!" << endl;
					proof = true;
				}
			}
			if (!proof) cout << "Nothing found!" << endl;
			system("pause");
			break;
		}
		case 5:
		{
			ofstream write("input.txt");
			write << n << endl;
			for (int i = 0; i < n; i++)
				write << p[i] << endl;
			write.close();


			return 0;
		}
		default: break;
		}
	} while (true);

	system("pause");
	return 0;
}