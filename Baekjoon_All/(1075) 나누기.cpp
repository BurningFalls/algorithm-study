#include <iostream>
using namespace std;

int main() {
	int N, F;
	int ans;
	cin >> N;
	cin >> F;
	N = int(N / 100) * 100;
	for (int i = 0; i <= 99; i++) {
		if ((N + i) % F == 0) {
			ans = i;
			break;
		}
	}
	if (ans < 10) {
		cout << "0";
	}
	cout << ans << endl;


	return 0;
}