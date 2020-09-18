#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int V;
vector<pair<int, int>> v[100001];
bool visited[100001] = { 0, };
int ans;
int start;

void DFS(int node, int sum) {
	int len = v[node].size();
	bool flag = false;
	FOR(i, 0, len - 1) {
		int nn = v[node][i].first;
		int nd = v[node][i].second;
		if (visited[nn]) continue;
		visited[nn] = 1;
		flag = true;
		DFS(nn, sum + nd);
	}
	if (!flag) {
		if (ans < sum) {
			ans = sum;
			start = node;
		}
	}
}

int main() {
	FASTIO;
	cin >> V;
	int node, u, d;
	FOR(i, 1, V) {
		cin >> node;
		while (true) {
			cin >> u;
			if (u == -1)
				break;
			cin >> d;
			v[node].push_back(make_pair(u, d));
		}
	}
	ans = 0;
	visited[1] = 1;
	DFS(1, 0);

	memset(visited, 0, sizeof(visited));
	ans = 0;
	visited[start] = 1;
	DFS(start, 0);
	cout << ans;

	return 0;
}