#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 100001

int N, K;
vector<vector<int>> Edge(MAX, vector<int>());
vector<vector<int>> cnt(MAX, vector<int>(21, 0));
int maxi = 0;

void DFS(int node, int prev) {
	cnt[node][0] = 1;
	for (int next : Edge[node]) {
		if (next == prev) continue;
		DFS(next, node);
		FOR(i, 1, K) {
			cnt[node][i] += cnt[next][i - 1];
		}
	}
}

void Travel(int node, int prev) {
	int sum = 0;
	FOR(i, 0, K) {
		sum += cnt[node][i];
	}
	maxi = max(maxi, sum);

	for (int next : Edge[node]) {
		if (next == prev) continue;
		vector<int> tmp(K + 1, 0);
		tmp[0] = 1;
		FOR(i, 1, K) {
			tmp[i] = cnt[node][i] - cnt[next][i - 1];
		}
		FOR(i, 1, K) {
			cnt[next][i] += tmp[i - 1];
		}
		Travel(next, node);
	}
}

int main() {
	FASTIO;
	cin >> N >> K;
	FOR(i, 1, N - 1) {
		int u, v;
		cin >> u >> v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}

	DFS(1, 0);
	Travel(1, 0);

	cout << maxi;

	return 0;
}