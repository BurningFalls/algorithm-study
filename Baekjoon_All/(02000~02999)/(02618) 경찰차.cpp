#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, W;
pii arr[1001];
int dp[1001][1001];
vector<int> ans_v;

int DP(int A, int B) {
	int& ret = dp[A][B];
	if (A == W || B == W)
		return ret = 0;
	if (ret != -1)
		return ret;
	int node = max(A, B) + 1;
	if (A == 0)
		arr[0] = { 1, 1 };
	int distA = abs(arr[node].first - arr[A].first) + abs(arr[node].second - arr[A].second);
	if (B == 0)
		arr[0] = { N, N };
	int distB = abs(arr[node].first - arr[B].first) + abs(arr[node].second - arr[B].second);
	int resultA = DP(node, B) + distA;
	int resultB = DP(A, node) + distB;
	return ret = min(resultA, resultB);
}

void BT(int A, int B) {
	int& ret = dp[A][B];
	if (A == W || B == W)
		return;
	int node = max(A, B) + 1;
	if (A == 0)
		arr[0] = { 1, 1 };
	int distA = abs(arr[node].first - arr[A].first) + abs(arr[node].second - arr[A].second);
	if (B == 0)
		arr[0] = { N, N };
	int distB = abs(arr[node].first - arr[B].first) + abs(arr[node].second - arr[B].second);
	int resultA = dp[node][B] + distA;
	int resultB = dp[A][node] + distB;
	if (resultA > resultB) {
		ans_v.push_back(2);
		BT(A, node);
	}
	else {
		ans_v.push_back(1);
		BT(node, B);
	}
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	cin >> N >> W;
	FOR(i, 1, W) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
	}
	cout << DP(0, 0) << "\n";
	BT(0, 0);
	for (int x : ans_v)
		cout << x << "\n";

	return 0;
}