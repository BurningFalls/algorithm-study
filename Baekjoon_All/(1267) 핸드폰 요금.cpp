#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[21];
	int ans1 = 0, ans2 = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		ans1 += (arr[i] / 30 + 1) * 10;
		ans2 += (arr[i] / 60 + 1) * 15;
	}
	if (ans1 > ans2) {
		cout << "M " << ans2;
	}
	else if (ans1 < ans2) {
		cout << "Y " << ans1;
	}
	else if (ans1 == ans2) {
		cout << "Y M " << ans1;
	}


	return 0;
}