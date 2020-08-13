#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][100001] = { 0, };

int main() {
	int N, K;
	vector<pair<int, int>> v; // v.first = W, v.second = V
	int W, V;
	cin >> N >> K;
	v.push_back(make_pair(-1, -1));
	for (int i = 1; i <= N; i++) {
		cin >> W >> V;
		v.push_back(make_pair(W, V));
	}
	for (int j = 1; j <= K; j++) {
		if (v[1].first <= j)
			dp[1][j] = v[1].second;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (v[i].first <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
			}
			else if (v[i].first > j) {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];

	return 0;
}