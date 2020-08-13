#include <iostream>
using namespace std;

int main() {
	int T;
	int A, B;
	int ans;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> A >> B;
		ans = 1;
		for (int i = 0; i < B; i++) {
			ans = (ans * A - 1) % 10 + 1;
		}
		cout << ans << endl;
	}

	return 0;
}