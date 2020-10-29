#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1000000 + 1

int N;
vector<int> v[MAX];
int dp[MAX][2];

int DFS(int cur, int pre, int state) {
	int& cache = dp[cur][state];
	if (cache != -1)
		return cache;
	int ans = 0;
	int len = v[cur].size();
	if (state == 0) {
		FOR(i, 0, len - 1) {
			int next = v[cur][i];
			if (next == pre) continue;
			ans += DFS(next, cur, 1);
		}
		return cache = ans;
	}
	else if (state == 1) {
		int temp1 = 0, temp2 = 0;
		FOR(i, 0, len - 1) {
			int next = v[cur][i];
			if (next == pre) continue;
			temp1 = DFS(next, cur, 0);
			temp2 = DFS(next, cur, 1);
			ans += min(temp1, temp2);
		}
		return cache = ans + 1;
	}
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	cin >> N;
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout << min(DFS(1, 0, 0), DFS(1, 0, 1));

	return 0;
}