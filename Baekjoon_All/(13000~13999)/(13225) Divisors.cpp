#include <iostream>
using namespace std;

int D(int num) {
	if (num == 1)
		return 1;
	int cnt = 2;
	for (int i = 2; i <= num - 1; i++) {
		if (num % i == 0)
			cnt++;
	}
	return cnt;
}

int main() {
	int C;
	int N;
	cin >> C;
	for (int a = 0; a < C; a++) {
		cin >> N;
		cout << N << " " << D(N) << "\n";
	}


	return 0;
}