#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	int A, B;
	string s;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> s;
		A = s[0] - '0';
		B = s[2] - '0';
		cout << A + B << "\n";
	}

	return 0;
}