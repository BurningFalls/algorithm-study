#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	int sum = 0;
	int cnt;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int j = 1; j <= sqrt(i); j++) {
			if (i % j == 0) {
				cnt++;
			}
		}
		sum += cnt;
	}
	cout << sum;

	return 0;
}