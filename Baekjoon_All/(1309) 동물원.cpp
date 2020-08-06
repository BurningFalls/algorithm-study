#include <iostream>
using namespace std;

int zoo(int n) {
	int ans[3];
	if (n == 1) {
		return 3;
	}
	else if (n == 2) {
		return 7;
	}
	else {
		ans[0] = 3;
		ans[1] = 7;
		for (int i = 0; i < n - 2; i++) {
			ans[2] = (2 * ans[1] + ans[0]) % 9901;
			ans[0] = ans[1];
			ans[1] = ans[2];
		}
	}
	return ans[2];
}

int main() {
	int N;
	cin >> N;
	cout << zoo(N) << endl;
	return 0;
}