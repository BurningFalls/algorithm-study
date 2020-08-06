#include <iostream>
using namespace std;

int a[1000];
int b[1000];

int seven(int score) {
	if (score == 1)
		return 5000000;
	else if (score >= 2 && score <= 3)
		return 3000000;
	else if (score >= 4 && score <= 6)
		return 2000000;
	else if (score >= 7 && score <= 10)
		return 500000;
	else if (score >= 11 && score <= 15)
		return 300000;
	else if (score >= 16 && score <= 21)
		return 100000;
	else
		return 0;
}

int eight(int score) {
	if (score == 1)
		return 5120000;
	else if (score >= 2 && score <= 3)
		return 2560000;
	else if (score >= 4 && score <= 7)
		return 1280000;
	else if (score >= 8 && score <= 15)
		return 640000;
	else if (score >= 16 && score <= 31)
		return 320000;
	else
		return 0;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < T; i++) {
		cout << seven(a[i]) + eight(b[i]) << endl;
	}
	return 0;
}