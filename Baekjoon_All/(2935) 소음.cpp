#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string A, B;
	char C;
	cin >> A >> C >> B;
	int lenA = A.size() - 1;
	int lenB = B.size() - 1;
	if (C == '*') {
		cout << "1";
		for (int i = 0; i < lenA + lenB; i++) {
			cout << "0";
		}
	}
	else if (C == '+') {
		if (lenA != lenB) {
			cout << "1";
			for (int i = 0; i < max(lenA, lenB) - min(lenA, lenB) - 1; i++) {
				cout << "0";
			}
			cout << "1";
			for (int i = 0; i < min(lenA, lenB); i++) {
				cout << "0";
			}
		}
		else if (lenA == lenB) {
			cout << "2";
			for (int i = 0; i < lenA; i++) {
				cout << "0";
			}
		}
	}

	return 0;
}