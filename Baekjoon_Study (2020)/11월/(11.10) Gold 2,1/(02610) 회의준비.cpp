#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int conn[101][101];
bool visited[101] = { 0, };
int maximum[101];
vector<int> ans_v;

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			conn[i][j] = INF;
		}
	}
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		conn[a][b] = 1;
		conn[b][a] = 1;
	}
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || i == k || k == j) continue;
				if (conn[i][k] == INF || conn[k][j] == INF) continue;
				conn[i][j] = min(conn[i][j], conn[i][k] + conn[k][j]);
			}
		}
	}
	FOR(i, 1, N) {
		int temp = 0;
		FOR(j, 1, N) {
			if (conn[i][j] == INF) continue;
			temp = max(temp, conn[i][j]);
		}
		maximum[i] = temp;
	}
	FOR(i, 1, N) {
		if (visited[i]) continue;
		visited[i] = 1;
		vector<int> v;
		FOR(j, 1, N) {
			if (conn[i][j] != INF) {
				v.push_back(j);
				visited[j] = 1;
			}
		}
		int len = v.size();
		int king = i;
		int minimum_max = maximum[i];
		FOR(j, 0, len - 1) {
			int node = v[j];
			if (minimum_max > maximum[node]) {
				minimum_max = maximum[node];
				king = node;
			}
		}
		ans_v.push_back(king);
	}
	sort(ans_v.begin(), ans_v.end());
	int ans_len = ans_v.size();
	cout << ans_len << "\n";
	FOR(i, 0, ans_len - 1)
		cout << ans_v[i] << "\n";

	return 0;
}