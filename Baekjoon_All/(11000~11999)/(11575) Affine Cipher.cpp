#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	int a, b;
	string s;
	char X;
	cin >> T;
	for (int A = 0; A < T; A++) {
		cin >> a >> b;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			X = (a * (int(s[i]) - 65) + b) % 26 + 65;
			cout << X;
		}
		cout << "\n";
	}

	return 0;
}