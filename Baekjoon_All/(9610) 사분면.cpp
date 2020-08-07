#include <iostream>
using namespace std;

int main() {
	int ans[6] = { 0, };
	int N;
	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		if (x > 0 && y > 0)
			ans[1]++;
		else if (x < 0 && y > 0)
			ans[2]++;
		else if (x < 0 && y < 0)
			ans[3]++;
		else if (x > 0 && y < 0)
			ans[4]++;
		else
			ans[5]++;
	}
	for (int i = 1; i <= 4; i++) {
		cout << "Q" << i << ": " << ans[i] << "\n";
	}
	cout << "AXIS: " << ans[5];


	return 0;
}