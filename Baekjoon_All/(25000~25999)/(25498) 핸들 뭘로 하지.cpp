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
#define MAX 500001

int N;
vector<char> v(MAX);
vector<vector<int>> Edge(MAX, vector<int>());
vector<bool> visited(MAX, 0);
string ans = "";

void BFS() {
	vector<int> t;
	ans += v[1];
	t.push_back(1);
	visited[1] = 1;
	int prev = 0;
	while (!t.empty()) {
		int maxi = 0;
		vector<int> tmp(t);
		FOR(i, 0, LEN(t) - 1) {
			for (int next : Edge[t[i]]) {
				if (visited[next]) continue;
				maxi = max(maxi, (int)v[next]);
			}
		}
		if (maxi != 0) {
			ans += maxi;
		}
		t.clear();
		FOR(i, 0, LEN(tmp) - 1) {
			for (int next : Edge[tmp[i]]) {
				if (visited[next]) continue;
				if (maxi != v[next]) continue;
				visited[next] = 1;
				t.push_back(next);
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> v[i];
	}
	FOR(i, 1, N - 1) {
		int u, v;
		cin >> u >> v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}
	BFS();
	cout << ans;

	return 0;
}