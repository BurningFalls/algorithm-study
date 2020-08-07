#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	if (N == 1) {
		cout << 1;
	}
	else if (N == 2) {
		if (M == 1 || M == 2)
			cout << 1;
		else if (M == 3 || M == 4)
			cout << 2;
		else if (M == 5 || M == 6)
			cout << 3;
		else
			cout << 4;
	}
	else {
		if (M >= 1 && M <= 4)
			cout << M;
		else if (M == 5 || M == 6)
			cout << 4;
		else
			cout << M - 2;
	}

	return 0;
}