#include <iostream>
using namespace std;

int main() {
	int C, K, P;
	int sum = 0;
	cin >> C >> K >> P;
	for (int i = 0; i <= C; i++) {
		sum += K * i + P * i * i;
	}
	cout << sum;

	return 0;
}