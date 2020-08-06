#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= 2 * N; i++) {
		if (i % 2 == 1) {
			if (N % 2 == 0) {
				for (int j = 1; j <= N / 2; j++) {
					cout << "* ";
				}
			}
			else {
				for (int j = 1; j <= N / 2 + 1; j++) {
					cout << "* ";
				}
			}
		}
		else if (i % 2 == 0) {
			for (int j = 1; j <= N / 2; j++) {
				cout << " *";
			}
		}
		cout << endl;
	}
}