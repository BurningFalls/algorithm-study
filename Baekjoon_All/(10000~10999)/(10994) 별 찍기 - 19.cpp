#include <iostream>
using namespace std;

void func() {


}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < (4 * N - 3) / 2; i++) {
		if (i == 0) {
			for (int j = 0; j < 4 * N - 3; j++) {
				cout << "*";
			}
		}
		else if (i % 2 == 0) {
			for (int j = 0; j < i / 2; j++) {
				cout << "* ";
			}
			for (int j = 0; j < 4 * (N - 1) + 1 - 2 * i; j++) {
				cout << "*";
			}
			for (int j = 0; j < i / 2; j++) {
				cout << " *";
			}
		}
		else if (i % 2 == 1) {
			for (int j = 0; j < i / 2 + 1; j++) {
				cout << "* ";
			}
			for (int j = 0; j < 4 * (N - 1) - 2 * i - 1; j++) {
				cout << " ";
			}
			for (int j = 0; j < i / 2 + 1; j++) {
				cout << " *";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < N - 1; i++) {
		cout << "* ";
	}
	cout << "*";
	for (int i = 0; i < N - 1; i++) {
		cout << " *";
	}
	cout << endl;
	for (int i = 0; i < (4 * N - 3) / 2; i++) {
		if (i == (4 * N - 3) / 2 - 1) {
			for (int j = 0; j < 4 * N - 3; j++) {
				cout << "*";
			}
		}
		else if (i % 2 == 1) {
			for (int j = 0; j < N - 2 - i / 2; j++) {
				cout << "* ";
			}
			for (int j = 0; j < 2 * i + 3; j++) {
				cout << "*";
			}
			for (int j = 0; j < N - 2 - i / 2; j++) {
				cout << " *";
			}
		}
		else if (i % 2 == 0) {
			for (int j = 0; j < N - 1 - i / 2; j++) {
				cout << "* ";
			}
			for (int j = 0; j < 2 * i + 1; j++) {
				cout << " ";
			}
			for (int j = 0; j < N - 1 - i / 2; j++) {
				cout << " *";
			}
		}
		cout << endl;
	}

	return 0;
}