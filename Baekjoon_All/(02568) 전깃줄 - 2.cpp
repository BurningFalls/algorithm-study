#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

vector<pair<int, int>> v;
int dp[100001];
int indexing[100001];
bool visited[100001] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	dp[0] = v[0].second;
	indexing[0] = 0;
	int idx = 0;
	FOR(i, 1, N - 1) {
		if (dp[idx] < v[i].second) {
			idx++;
			dp[idx] = v[i].second;
			indexing[i] = idx;
		}
		else {
			int lb = lower_bound(dp, dp + idx + 1, v[i].second) - dp;
			dp[lb] = v[i].second;
			indexing[i] = lb;
		}
	}
	int max_index = 0;
	FOR(i, 0, N - 1) {
		if (indexing[i] > max_index) {
			max_index = indexing[i];
			idx = i;
		}
	}
	visited[idx] = 1;
	int idx_idx = idx - 1;
	int idx_val = indexing[idx];
	while (idx_idx >= 0) {
		if (indexing[idx_idx] + 1 == idx_val) {
			visited[idx_idx] = 1;
			idx_val--;
		}
		idx_idx--;
	}
	cout << N - (max_index + 1) << "\n";
	FOR(i, 0, N - 1) {
		if (visited[i]) continue;
		cout << v[i].first << "\n";
	}

	return 0;
}