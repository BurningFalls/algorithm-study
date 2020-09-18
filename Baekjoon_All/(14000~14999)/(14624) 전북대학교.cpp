#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N % 2 == 1) {
		for (int i = 0; i < N; i++) {
			cout << "*";
		}
		cout << endl;
		for (int i = 0; i < N / 2; i++) {
			cout << " ";
		}
		cout << "*" << endl;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2 - 1 - i; j++) {
				cout << " ";
			}
			cout << "*";
			for (int j = 0; j < 2 * i + 1; j++) {
				cout << " ";
			}
			cout << "*" << endl;
		}
	}
	else if (N % 2 == 0) {
		cout << "I LOVE CBNU";
	}

	return 0;
}