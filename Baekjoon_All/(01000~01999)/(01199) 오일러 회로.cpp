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
#define MAX 1001

int N;
vector<vector<pii>> Edge(MAX, vector<pii>());
vector<vector<int>> edge_cnt(MAX, vector<int>(MAX));

void DFS(int node) {
	while (!Edge[node].empty()) {
		while (!Edge[node].empty() && edge_cnt[node][Edge[node].back().first] == 0) {
			Edge[node].pop_back();
		}
		if (Edge[node].empty()) break;
		pii next = Edge[node].back();
		if (--Edge[node].back().second == 0) {
			Edge[node].pop_back();
		}
		edge_cnt[node][next.first]--;
		edge_cnt[next.first][node]--;
		DFS(next.first);
	}
	cout << node << " ";
}

int main() {
	FASTIO;
	bool flag = true;
	cin >> N;
	FOR(i, 1, N) {
		int cnt = 0;
		FOR(j, 1, N) {
			int num;
			cin >> num;
			edge_cnt[i][j] += num;
			cnt += num;
			if (num != 0) {
				Edge[i].push_back({ j, num });
			}
		}
		if (cnt % 2 == 1) {
			flag = false;
		}
	}
	if (!flag) {
		cout << -1;
	}
	else {
		DFS(1);
	}

	return 0;
}