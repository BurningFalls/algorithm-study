#include <iostream>
using namespace std;

int main() {
	int n;
	int ans = 1;
	cin >> n;
	for (int i = 0; i < (n + 1) / 2; i++) {
		ans = (ans * 2) % 16769023;
	}
	cout << ans;

	return 0;
}