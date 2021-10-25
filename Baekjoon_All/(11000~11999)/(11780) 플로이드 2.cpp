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

int Floyd[101][101] = { 0, };
vector<int> city[101][101];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			Floyd[i][j] = INF;
		}
	}
	FOR(i, 1, M) {
		int a, b, c;
		cin >> a >> b >> c;
		Floyd[a][b] = min(Floyd[a][b], c);
	}
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || i == k || k == j) continue;
				if (Floyd[i][k] == INF || Floyd[k][j] == INF) continue;
				if (Floyd[i][j] > Floyd[i][k] + Floyd[k][j]) {
					Floyd[i][j] = Floyd[i][k] + Floyd[k][j];
					city[i][j].clear();
					for (int x : city[i][k]) {
						city[i][j].push_back(x);
					}
					city[i][j].push_back(k);
					for (int x : city[k][j]) {
						city[i][j].push_back(x);
					}
				}
			}
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (Floyd[i][j] == INF)
				cout << 0 << " ";
			else
				cout << Floyd[i][j] << " ";
		}
		cout << "\n";
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (Floyd[i][j] == INF) {
				cout << 0;
			}
			else {
				cout << LEN(city[i][j]) + 2 << " ";
				cout << i << " ";
				for (int x : city[i][j]) {
					cout << x << " ";
				}
				cout << j;
			}
			cout << "\n";
		}
	}

	return 0;
}