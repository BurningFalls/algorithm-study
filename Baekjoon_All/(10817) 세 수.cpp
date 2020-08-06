#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (A >= B) {
		if (B >= C) {
			cout << B << endl;
		}
		else if (B < C) {
			if (A >= C) {
				cout << C << endl;
			}
			else if (A < C) {
				cout << A << endl;
			}
		}
	}
	if (A < B) {
		if (A >= C) {
			cout << A << endl;
		}
		else if (A < C) {
			if (B >= C) {
				cout << C << endl;
			}
			else if (B < C) {
				cout << B << endl;
			}
		}
	}

}