#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int N;
	int M, K;
	int A;
	int arr[1001];
	int temp;
	int ans = 0;
	int idx = 0;
	cin >> N;
	cin >> M >> K;
	temp = M * K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N, compare);
	while (temp > 0 && idx < N) {
		temp -= arr[idx];
		idx++;
		ans++;
	}
	if (temp > 0)
		cout << "STRESS";
	else
		cout << ans;

	return 0;
}