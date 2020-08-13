#include <iostream>
#include <math.h>
using namespace std;
int check(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return -1;
	}
	cout << n << "\n";
	return 1;
}
int main() {
	int M, N;
	cin >> M >> N;
	if (M == 1)
		M++;
	for (int i = M; i <= N; i++) {
		check(i);
	}
	return 0;
}