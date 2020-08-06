#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			for (int j = 0; j < N; j++) {
				cout << "*";
			}
		}
		else {
			for (int j = 0; j < i; j++) {
				cout << " ";
			}
			cout << "*";
			for (int j = 0; j < N - 2; j++) {
				cout << " ";
			}
			cout << "*";
		}
		for (int j = 0; j < 2 * N - 3 - 2 * i; j++) {
			cout << " ";
		}
		if (i == 0) {
			for (int j = 0; j < N; j++) {
				cout << "*";
			}
		}
		else {
			if (i != N - 1) {
				cout << "*";
			}
			for (int j = 0; j < N - 2; j++) {
				cout << " ";
			}
			cout << "*";
		}
		cout << endl;
	}

	for (int i = N - 2; i >= 0; i--) {
		if (i == 0) {
			for (int j = 0; j < N; j++) {
				cout << "*";
			}
		}
		else {
			for (int j = 0; j < i; j++) {
				cout << " ";
			}
			cout << "*";
			for (int j = 0; j < N - 2; j++) {
				cout << " ";
			}
			cout << "*";
		}
		for (int j = 0; j < 2 * N - 3 - 2 * i; j++) {
			cout << " ";
		}
		if (i == 0) {
			for (int j = 0; j < N; j++) {
				cout << "*";
			}
		}
		else {
			cout << "*";
			for (int j = 0; j < N - 2; j++) {
				cout << " ";
			}
			cout << "*";
		}
		cout << endl;
	}




	return 0;
}