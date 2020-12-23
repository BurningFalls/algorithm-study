#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N, M;
vector<pii> v[501];
ll dist[501];

bool BF() {
	bool cycle = false;
	int a, b, c;
	dist[1] = 0;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int len = v[j].size();
			FOR(k, 0, len - 1) {
				int cur = j;
				int next = v[j][k].first;
				int cost = v[j][k].second;
				if (dist[j] == INF) continue;
				if (cur == next) continue;
				if (dist[next] > cost + dist[cur]) {
					dist[next] = cost + dist[cur];
					if (i == N)
						cycle = true;
				}
			}
		}
	}
	return cycle;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N)
		dist[i] = INF;
	FOR(i, 1, M) {
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back({ B, C });
	}
	if (BF())
		cout << -1;
	else {
		FOR(i, 2, N) {
			if (dist[i] == INF)
				cout << -1;
			else
				cout << dist[i];
			cout << "\n";
		}
	}

	return 0;
}