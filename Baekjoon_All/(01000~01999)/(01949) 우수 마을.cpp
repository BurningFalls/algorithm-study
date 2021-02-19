#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
int arr[10001];
vector<int> edge[10001];
int dp[10001][2];
bool visited[10001] = { 0, };

int DP(int node, bool flag) {
	int& ret = dp[node][flag];
	if (ret != -1)
		return ret;
	visited[node] = 1;
	ret = 0;
	for (int next : edge[node]) {
		if (visited[next]) continue;
		int temp;
		if (flag == 0)
			temp = max(DP(next, 0), DP(next, 1));
		else if (flag == 1)
			temp = DP(next, 0);
		ret += temp;
	}
	visited[node] = 0;
	if (flag == 1)
		ret += arr[node];
	return ret;
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	cout << max(DP(1, 0), DP(1, 1));

	return 0;
}