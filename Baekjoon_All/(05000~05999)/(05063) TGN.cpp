#include <iostream>
using namespace std;

int main() {
	int N;
	int r, e, c;
	cin >> N;
	for (int a = 0; a < N; a++) {
		cin >> r >> e >> c;
		if (e - r > c) {
			cout << "advertise" << "\n";
		}
		else if (e - r < c) {
			cout << "do not advertise" << "\n";
		}
		else if (e - r == c) {
			cout << "does not matter" << "\n";
		}
	}

	return 0;
}