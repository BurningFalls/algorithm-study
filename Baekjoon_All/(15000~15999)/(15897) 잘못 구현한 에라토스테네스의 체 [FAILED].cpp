#include <iostream>
using namespace std;

int main() {
	int N;
	int div_cnt = 0;
	long long int sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0)
			div_cnt++;
		sum += N / i;
	}
	sum += N - div_cnt;
	cout << sum;

	return 0;
}