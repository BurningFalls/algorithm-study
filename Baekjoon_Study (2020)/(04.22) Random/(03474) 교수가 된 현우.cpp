#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int T;
	int N;
	int i;
	int sum;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> N;
		sum = 0;
		i = 5;
		while (i <= N) {
			sum += N / i;
			i = i * 5;
		}
		cout << sum << "\n";
	}


	return 0;
}