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

int N, M;
vector<vector<int>> Edge(MAX, vector<int>());
vector<ll> comp(MAX, 0);

void DFS(int node, int prev, ll cp) {
	comp[node] += cp;
	for (int next : Edge[node]) {
		if (next == prev) continue;
		DFS(next, node, comp[node]);
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		if (i == 1) continue;
		Edge[num].push_back(i);
	}
	FOR(i, 1, M) {
		int num, w;
		cin >> num >> w;
		comp[num] += w;
	}

	DFS(1, 0, 0);
	
	FOR(i, 1, N) {
		cout << comp[i] << " ";
	}

	return 0;
}