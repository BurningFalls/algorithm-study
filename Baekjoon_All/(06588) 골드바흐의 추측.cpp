#include <iostream>
#include <math.h>
using namespace std;

bool Check(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	int flag;
	bool prime_flag[1000001] = { 0, };
	for (int i = 3; i <= 999999; i += 2) {
		if (Check(i))
			prime_flag[i] = 1;
	}
	while (true) {
		cin >> N;
		flag = false;
		if (N == 0)
			break;
		for (int i = 3; i <= N / 2; i += 2) {
			if (prime_flag[i] && prime_flag[N - i]) {
				cout << N << " = " << i << " + " << N - i << "\n";
				flag = true;
				break;
			}
		}
		if (flag == false) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}