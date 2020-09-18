#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][3];
int ans[1001];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
		if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) {
			ans[i] = 10000 + arr[i][0] * 1000;
		}
		else if (arr[i][0] != arr[i][1] && arr[i][0] != arr[i][2] && arr[i][1] != arr[i][2]) {
			ans[i] = max({ arr[i][0], arr[i][1], arr[i][2] }) * 100;
		}
		else {
			if (arr[i][0] == arr[i][1] || arr[i][0] == arr[i][2])
				ans[i] = 1000 + arr[i][0] * 100;
			else if (arr[i][1] == arr[i][2])
				ans[i] = 1000 + arr[i][1] * 100;
		}
	}
	cout << *max_element(ans, ans + N);

	return 0;
}