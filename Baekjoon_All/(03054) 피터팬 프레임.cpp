#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int len;
	cin >> str;
	len = str.size();

	for (int i = 0; i < 4 * len + 1; i++) {
		if (i % 4 == 2) {
			if ((i / 4 + 1) % 3 == 0)
				cout << "*";
			else
				cout << "#";
		}
		else
			cout << ".";
	}
	cout << endl;

	for (int i = 0; i < 4 * len + 1; i++) {
		if (i % 2 == 1) {
			if ((i / 2) % 6 == 4 || (i / 2) % 6 == 5)
				cout << "*";
			else
				cout << "#";
		}
		else
			cout << ".";
	}
	cout << endl;

	for (int i = 0; i < 4 * len + 1; i++) {
		if (i % 2 == 0) {
			if (i % 4 == 2) {
				cout << str[i / 4];
			}
			else {
				if ((len % 3 == 2) && i == 4 * len)
					cout << "#";
				else {
					if (i != 0 && (i % 12 == 0 || i % 12 == 8))
						cout << "*";
					else
						cout << "#";
				}
			}
		}
		else
			cout << ".";
	}
	cout << endl;

	for (int i = 0; i < 4 * len + 1; i++) {
		if (i % 2 == 1) {
			if ((i / 2) % 6 == 4 || (i / 2) % 6 == 5)
				cout << "*";
			else
				cout << "#";
		}
		else
			cout << ".";
	}
	cout << endl;

	for (int i = 0; i < 4 * len + 1; i++) {
		if (i % 4 == 2) {
			if ((i / 4 + 1) % 3 == 0)
				cout << "*";
			else
				cout << "#";
		}
		else
			cout << ".";
	}

	return 0;
}