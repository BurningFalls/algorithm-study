#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

struct NODE {
	int S;
	int E;
	int idx;
};

int dist[301][301];
vector<vector<NODE>> quest(302);
vector<int> ans(500001);

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> dist[i][j];
		}
	}
	FOR(q, 1, Q) {
		int c, s, e;
		cin >> c >> s >> e;
		quest[c].push_back({ s, e, q });
	}
	for (NODE x : quest[1]) {
		if (x.S != x.E && dist[x.S][x.E] == 0) {
			ans[x.idx] = -1;
		}
		else {
			ans[x.idx] = dist[x.S][x.E];
		}
	}
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || i == k || k == j) continue;
				if (dist[i][k] == 0 || dist[k][j] == 0) continue;
				if (dist[i][j] == 0) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
				else {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		for (NODE x : quest[k + 1]) {
			if (x.S != x.E && dist[x.S][x.E] == 0) {
				ans[x.idx] = -1;
			}
			else {
				ans[x.idx] = dist[x.S][x.E];
			}
		}
	}
	FOR(i, 1, Q) {
		cout << ans[i] << "\n";
	}

	return 0;
}