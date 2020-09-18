#include <iostream>
using namespace std;

int main() {
	long long int A, B;
	cin >> A >> B;
	if (A < B) {
		cout << B - A - 1;
		if (B - A - 1 >= 1) {
			cout << "\n";
			for (long long int i = A + 1; i < B; i++) {
				cout << i << " ";
			}
		}
	}
	else if (A > B) {
		cout << A - B - 1;
		if (A - B - 1 >= 1) {
			cout << "\n";
			for (long long int i = B + 1; i < A; i++) {
				cout << i << " ";
			}
		}
	}
	else if (A == B)
		cout << 0;

	return 0;
}