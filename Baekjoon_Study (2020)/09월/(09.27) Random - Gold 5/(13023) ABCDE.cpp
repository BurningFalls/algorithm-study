#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
vector<int> v[2001];
int indegree[2001] = { 0, };
bool visited[2001] = { 0, };
bool flag;

void DFS(int node, int cnt) {
	if (flag)
		return;
	if (cnt == 5) {
		flag = true;
		return;
	}
	int len = v[node].size();
	int temp;
	FOR(i, 0, len - 1) {
		int nn = v[node][i];
		if (visited[nn]) continue;
		visited[nn] = 1;
		DFS(nn, cnt + 1);
		visited[nn] = 0;
		if (flag)
			break;
	}
}

int main() {
	FASTIO;
	int cnt = 0;
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		indegree[a]++;
		indegree[b]++;
	}
	FOR(i, 0, N - 1) {
		if (indegree[i] == 1)
			cnt++;
	}
	if (cnt == 0)
		cout << 1;
	else {
		FOR(i, 0, N - 1) {
			flag = false;
			visited[i] = 1;
			DFS(i, 1);
			visited[i] = 0;
			if (flag)
				break;
		}
		cout << flag;
	}

	return 0;
}