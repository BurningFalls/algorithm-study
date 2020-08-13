#include <iostream>
using namespace std;

int main() {
	int T;
	int N;
	int sum;
	int num;
	cin >> T;
	for (int i = 0; i < T; i++) {
		sum = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> num;
			sum += num;
		}
		cout << sum << "\n";
	}

	return 0;
}