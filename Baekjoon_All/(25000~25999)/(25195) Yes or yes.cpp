#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MAX 100001

int N, M, S;
vector<vector<int>> Edge(MAX, vector<int>());
vector<int> Check(MAX, 0);

bool DFS(int node) {
	if (Check[node]) {
		return true;
	}
	bool flag = true;
	bool is_end = true;
	for (int next : Edge[node]) {
		is_end = false;
		flag &= DFS(next);
	}
	if (is_end) flag = false;
	return flag;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int u, v;
		cin >> u >> v;
		Edge[u].push_back(v);
	}
	cin >> S;
	FOR(i, 1, S) {
		int s;
		cin >> s;
		Check[s] = 1;
	}
	cout << (DFS(1) ? "Yes" : "yes");

	return 0;
}