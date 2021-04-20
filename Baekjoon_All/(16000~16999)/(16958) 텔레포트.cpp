#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct CITY {
	int s;
	int x;
	int y;
};

CITY city[1001];
int dist[1001][1001];
int N, T;

int main() {
	FASTIO;
	cin >> N >> T;
	FOR(i, 1, N) {
		int is, ix, iy;
		cin >> is >> ix >> iy;
		city[i] = { is, ix, iy };
	}

	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			int d = abs(city[i].x - city[j].x) + abs(city[i].y - city[j].y);
			if (city[i].s && city[j].s)
				d = min(d, T);
			dist[i][j] = d;
			dist[j][i] = d;
		}
	}

	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || i == k || k == j) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int M;
	cin >> M;
	FOR(i, 1, M) {
		int A, B;
		cin >> A >> B;
		cout << dist[A][B] << "\n";
	}

	return 0;
}