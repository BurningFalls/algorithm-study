#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

bool visited[51] = { 0, };
vector<int> v[51];
queue<int> q;

void BFS() {
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		int len = v[n].size();
		FOR(i, 0, len - 1) {
			int nn = v[n][i];
			if (visited[nn]) continue;
			visited[nn] = 1;
			q.push(nn);
		}
	}
}

int main() {
	FASTIO;
	int N, M;
	int T_cnt, T, P_cnt[51], P[51][51];
	int ans = 0;
	
	cin >> N >> M;
	cin >> T_cnt;
	FOR(i, 1, T_cnt) {
		cin >> T;
		q.push(T);
		visited[T] = 1;
	}
	FOR(i, 1, M) {
		cin >> P_cnt[i];
		FOR(j, 1, P_cnt[i]) {
			cin >> P[i][j];
			if (j != 1) {
				v[P[i][j - 1]].push_back(P[i][j]);
				v[P[i][j]].push_back(P[i][j - 1]);
			}
		}
	}
	BFS();
	FOR(i, 1, M) {
		bool flag = false;
		FOR(j, 1, P_cnt[i]) {
			if (visited[P[i][j]]) {
				flag = true;
				break;
			}
		}
		if (!flag)
			ans++;
	}
	cout << ans;

	return 0;
}