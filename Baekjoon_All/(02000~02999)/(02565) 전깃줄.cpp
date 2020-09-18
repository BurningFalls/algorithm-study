#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	vector<pair<int, int>> v;
	int dp[101];
	int x, y;
	int temp;
	int total_max = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		temp = 0;
		for (int j = 0; j < i; j++) {
			if (v[j].second < v[i].second) {
				temp = max(temp, dp[j]);
			}
		}
		dp[i] = temp + 1;
		total_max = max(total_max, dp[i]);
	}
	cout << N - total_max;

	return 0;
}