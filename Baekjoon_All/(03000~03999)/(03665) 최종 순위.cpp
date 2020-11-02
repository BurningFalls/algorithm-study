#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[501];
int indegree[501];
bool conn[501][501];
int ans[501];

int TP() {
	queue<int> q;
	FOR(i, 1, N) {
		if (indegree[i] == 0)
			q.push(i);
	}
	if (q.size() >= 2)
		return 0;
	if (q.size() == 0)
		return -1;
	FOR(i, 1, N) {
		if (q.size() >= 2)
			return 0;
		if (q.size() == 0)
			return -1;
		int node = q.front();
		q.pop();
		ans[i] = node;
		FOR(j, 1, N) {
			if (!conn[node][j]) continue;
			conn[node][j] = 0;
			indegree[j]--;
			if (indegree[j] == 0)
				q.push(j);
		}
	}
	return 1;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		memset(conn, 0, sizeof(conn));
		memset(indegree, 0, sizeof(indegree));
		int M;
		cin >> N;
		FOR(i, 1, N)
			cin >> arr[i];
		FOR(i, 1, N) FOR(j, i + 1, N)
			conn[arr[i]][arr[j]] = 1;
		cin >> M;
		FOR(i, 1, M) {
			int a, b;
			cin >> a >> b;
			if (conn[a][b] == 1) {
				conn[a][b] = 0;
				conn[b][a] = 1;
			}
			else if (conn[b][a] == 1) {
				conn[b][a] = 0;
				conn[a][b] = 1;
			}
		}
		FOR(i, 1, N) FOR(j, 1, N)
			indegree[i] += conn[j][i];
		int flag = TP();
		if (flag == 1) {
			FOR(i, 1, N)
				cout << ans[i] << " ";
		}
		else if (flag == 0)
			cout << "?";
		else if (flag == -1)
			cout << "IMPOSSIBLE";
		cout << "\n";
	}

	return 0;
}