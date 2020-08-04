#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, A, B;
	int round = 1;
	int num = 1;
	cin >> N >> A >> B;
	while (true) {
		if (num < N && N <= num * 2)
			break;
		num++;
	}
	while (round <= num) {
		if (min(A, B) % 2 == 1 && abs(A - B) == 1)
			break;
		A = (A + 1) / 2;
		B = (B + 1) / 2;
		round++;
	}

	if (round > num)
		cout << -1 << endl;
	else
		cout << round << endl;

	return 0;
}