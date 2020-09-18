#include <iostream>
using namespace std;

int main() {
	int T;
	int s;
	int n;
	int arr[1001];
	int q, p;
	int sum;
	cin >> T;
	for (int a = 0; a < T; a++) {
		sum = 0;
		cin >> s;
		sum += s;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> q >> p;
			sum += q * p;
		}
		cout << sum << "\n";
	}

	return 0;
}