#include <iostream>
using namespace std;

int N, S;
int arr[21];
int check[21] = { 0, };
int ans = 0;

void DFS(int cnt) {
	if (cnt == N) {
		int sum = 0;
		int cnt2 = 0;
		for (int i = 0; i < N; i++) {
			if (!check[i])
				cnt2++;
		}
		if (cnt2 == N)
			return;
		for (int i = 0; i < N; i++) {
			if (check[i])
				sum += arr[i];
		}
		if (sum == S)
			ans++;
		return;
	}

	for (int i = 0; i <= 1; i++) {
		check[cnt] = i;
		DFS(cnt + 1);
	}
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	DFS(0);
	cout << ans;

	return 0;
}