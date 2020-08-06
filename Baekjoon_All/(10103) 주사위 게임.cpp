#include <iostream>
using namespace std;

int main() {
	int n;
	int score1 = 100, score2 = 100;
	int a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a < b) {
			score1 -= b;
		}
		else if (a > b) {
			score2 -= a;
		}
	}
	cout << score1 << "\n" << score2;

	return 0;
}