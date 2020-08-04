#include <iostream>
using namespace std;

int N, L;
int map[101][101];
int arr[101];

bool Check(int* nums) {
	int node = 0;
	int cnt;
	int slide[101] = { 0, };
	while (node < N - 1) {
		if (nums[node] == nums[node + 1]) {
			node++;
		}
		else if (nums[node] - nums[node + 1] == 1) {
			cnt = 1;
			for (int i = node + 2; i < N; i++) {
				if (nums[node + 1] == nums[i])
					cnt++;
				else
					break;
			}
			if (cnt < L)
				return false;
			else if (cnt > L)
				cnt = L;
			for (int i = node + 1; i <= node + cnt; i++) {
				slide[i] = 1;
			}
			node += cnt;
		}
		else if (nums[node] - nums[node + 1] >= 2)
			return false;
		else
			node++;
	}

	node = N - 1;
	while (node > 0) {
		if (nums[node] == nums[node - 1]) {
			node--;
		}
		else if (nums[node] - nums[node - 1] == 1) {
			cnt = 1;
			for (int i = node - 2; i >= 0; i--) {
				if (nums[node - 1] == nums[i])
					cnt++;
				else
					break;
			}
			if (cnt < L)
				return false;
			else if (cnt > L)
				cnt = L;
			for (int i = node - 1; i >= node - cnt; i--) {
				if (slide[i] == 1)
					return false;
				slide[i] = 1;
			}
			node -= cnt;
		}
		else if (nums[node] - nums[node - 1] >= 2)
			return false;
		else
			node--;
	}
	return true;
}

int main() {
	int ans = 0;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[j] = map[i][j];
		}
		if (Check(arr))
			ans++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[j] = map[j][i];
		}
		if (Check(arr))
			ans++;
	}
	cout << ans;

	return 0;
}