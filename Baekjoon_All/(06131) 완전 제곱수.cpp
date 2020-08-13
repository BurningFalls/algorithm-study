#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	int ans = 0;
	cin >> N;
	for (int B = 1; B <= 500; B++) {
		for (int A = B; A <= 500; A++) {
			if (A * A == B * B + N)
				ans++;
		}
	}
	cout << ans;

	return 0;
}