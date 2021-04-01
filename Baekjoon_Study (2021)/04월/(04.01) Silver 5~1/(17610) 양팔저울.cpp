#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int K;
int gram[14];
bool dp[14][2600001] = { 0, };
int all_sum = 0;

void DFS(int node, int sum) {
	if (node > K) return;
	if (dp[node][sum]) return;
	dp[node][sum] = 1;
	DFS(node + 1, sum + gram[node]);
	DFS(node + 1, abs(sum - gram[node]));
	DFS(node + 1, sum);
}

int main() {
	FASTIO;
	cin >> K;
	FOR(i, 0, K - 1) {
		cin >> gram[i];
		all_sum += gram[i];
	}
	DFS(0, 0);
	int cnt = 0;
	FOR(i, 0, all_sum) {
		if (!dp[K][i])
			cnt++;
	}
	cout << cnt;

	return 0;
}