#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

pii edge[200001];
int R[200001];
int idx[100001] = { 0, };
vector<int> edge_v[200001];
bool unuse[200001] = { 0, };
bool flag = true;

void DFS(int node, int prev) {
	for (int next : edge_v[node]) {
		if (prev == next) continue;
		if (idx[node] == idx[next]) {
			flag = false;
			return;
		}
		if (idx[next] == 0) {
			idx[next] = 3 - idx[node];
			DFS(next, node);
		}
		if (!flag)
			return;
	}
}

int main() {
	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		edge[i] = { a, b };
	}
	FOR(i, 1, K) {
		cin >> R[i];
		unuse[R[i]] = 1;
	}
	int tmp = 0;
	FOR(i, 1, M) {
		if (unuse[i]) continue;
		int a = edge[i].first;
		if (i == 1)
			tmp = a;
		int b = edge[i].second;
		edge_v[a].push_back(b);
		edge_v[b].push_back(a);
	}

	idx[tmp] = 1;
	DFS(tmp, 0);
	if (!flag) {
		cout << -1;
		return 0;
	}

	int pos = K;
	while (pos >= 1) {
		int a = edge[R[pos]].first;
		int b = edge[R[pos]].second;
		if (idx[a] == idx[b])
			break;
		pos--;
	}
	cout << pos << "\n";
	int one_cnt = 0;
	int two_cnt = 0;
	FOR(i, 1, N) {
		if (idx[i] == 1)
			one_cnt++;
		else if (idx[i] == 2)
			two_cnt++;
	}
	cout << min(one_cnt, two_cnt) << " " << max(one_cnt, two_cnt);

	return 0;
}