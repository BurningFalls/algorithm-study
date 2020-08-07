#include <iostream>
using namespace std;

int main() {
	int R, C, A, B;
	cin >> R >> C;
	cin >> A >> B;
	for (int i = 0; i < R * A; i++) {
		if (i / A == 0 || (i / A) % 2 == 0) {
			for (int j = 0; j < C * B; j++) {
				if (j / B == 0 || (j / B) % 2 == 0) {
					cout << "X";
				}
				else if ((j / B) % 2 == 1) {
					cout << ".";
				}
			}
			cout << endl;
		}
		else if ((i / A) % 2 == 1) {
			for (int j = 0; j < C * B; j++) {
				if (j / B == 0 || (j / B) % 2 == 0) {
					cout << ".";
				}
				else if ((j / B) % 2 == 1) {
					cout << "X";
				}
			}
			cout << endl;
		}
	}

	return 0;
}