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

struct NODE {
	int vertex;
	bool flag;
	int idx;
};

int N;
vector<vector<NODE>> Edge(100001, vector<NODE>());
vector<bool> Flip(100001, 0);
vector<bool> Ans(100001, 0);
int min_flip = INF;

int Init(int node, int prev) {
	int sum = 0;
	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].vertex;
		bool flag = Edge[node][i].flag;
		int idx = Edge[node][i].idx;
		if (next == prev) continue;
		Flip[idx] = flag;
		sum += Init(next, node) + flag;
	}
	return sum;
}

void DFS(int node, int prev, int flip_cnt) {
	if (min_flip > flip_cnt) {
		min_flip = flip_cnt;
		FOR(i, 0, N - 2) {
			Ans[i] = Flip[i];
		}
	}
	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].vertex;
		bool flag = Edge[node][i].flag;
		int idx = Edge[node][i].idx;
		if (next == prev) continue;
		if (flag) {
			Flip[idx] = 0;
			DFS(next, node, flip_cnt - 1);
			Flip[idx] = 1;
		}
		else if (!flag) {
			Flip[idx] = 1;
			DFS(next, node, flip_cnt + 1);
			Flip[idx] = 0;
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 2) {
		int u, v;
		cin >> u >> v;
		Edge[u].push_back({ v, 0, i });
		Edge[v].push_back({ u, 1, i });
	}
	int flip_cnt = Init(1, 0);
	DFS(1, 0, flip_cnt);
	FOR(i, 0, N - 2) {
		cout << Ans[i];
	}

	return 0;
}