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

int N, K;
vector<vector<int>> Edge(10001, vector<int>());
vector<int> Depth(10001, 0);
vector<int> Cnt(10001, 0);
vector<int> ch_Cnt(10001, 0);
vector<int> Parent(10001, 0);
int max_depth = 0;

int DFS(int node, int prev, int depth) {
	int cnt = 1;
	Depth[node] = depth;
	Parent[node] = prev;
	max_depth = max(max_depth, depth);
	for (int next : Edge[node]) {
		if (next == prev) continue;
		cnt += DFS(next, node, depth + 1);
	}
	Cnt[node] = cnt;
	ch_Cnt[node] = Cnt[node];
	return cnt;
}

int main() {
	FASTIO;
	cin >> N >> K;
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}
	DFS(1, 0, 0);

	vector<vector<int>> idx(max_depth + 1, vector<int>());
	FOR(i, 1, N) {
		idx[Depth[i]].push_back(i);
	}
	int sub = 0;
	ROF(i, max_depth, 1) {
		int mini = INF;
		int min_idx = 0;
		int len = LEN(idx[i]);
		PQ<pii> pq;
		FOR(j, 0, len - 1) {
			int node = idx[i][j];
			pq.push({ -ch_Cnt[node], node });
		}
		FOR(j, 1, len - K) {
			int cnt = -pq.top().first;
			int node = pq.top().second;
			pq.pop();
			sub += cnt;
			ch_Cnt[Parent[node]] -= Cnt[node];
		}
	}
	cout << N - sub;

	return 0;
}