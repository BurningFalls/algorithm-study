#include <iostream>
using namespace std;

int main() {
	long long int N;
	long long int sum = 0;
	cin >> N;
	for (long long int i = 1; i < N; i++) {
		sum += i * (N + 1);
	}
	cout << sum << endl;

	return 0;
}