#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

vector<int> v[100001];
int n, a, b, da, db;
int visited_b;
int visited[100001] = { 0, };
int max_visited = 1;
int cnt[100001] = { 0, };

void BFS(int leaf) {
	FOR(i, 1, n)
		visited[i] = 0;
	queue<int> q;
	q.push(leaf);
	visited[leaf] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		int len = v[node].size();
		FOR(i, 0, len - 1) {
			int nn = v[node][i];
			if (visited[nn]) continue;
			visited[nn] = visited[node] + 1;
			max_visited = max(max_visited, visited[nn]);
			q.push(nn);
		}
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> a >> b >> da >> db;
		int leaf;
		FOR(i, 1, n)
			v[i].clear();
		FOR(i, 1, n) {
			visited[i] = 0;
			cnt[i] = 0;
		}
		max_visited = 1;
		FOR(i, 1, n - 1) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
			cnt[a]++;
			cnt[b]++;
		}
		FOR(i, 1, n) {
			if (cnt[i] == 1) {
				leaf = i;
				break;
			}
		}
		BFS(leaf);
		int dist_ab = abs(visited[b] - visited[a]);
		int tree_dia = max_visited - 1;
		int temp;
		if (tree_dia % 2 == 0)
			temp = tree_dia / 2;
		else
			temp = tree_dia / 2 + 1;
		if (dist_ab <= da)
			cout << "Alice";
		else {
			if (da >= temp)
				cout << "Alice";
			else {
				if (da >= db - 1)
					cout << "Alice";
				else
					cout << "Bob";
			}
		}
		cout << "\n";
	}

	return 0;
}