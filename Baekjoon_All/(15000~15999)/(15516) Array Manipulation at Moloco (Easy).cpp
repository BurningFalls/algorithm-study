#include <iostream>
using namespace std;

int main() {
	int n;
	int cnt;
	int arr[1001];
	int ans[1001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				cnt++;
		}
		ans[i] = cnt;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}


	return 0;
}