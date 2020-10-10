#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool conn[401][401] = { 0, };

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, K) {
		int a, b;
		cin >> a >> b;
		conn[a][b] = 1;
	}
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || i == k || k == j) continue;
				if (conn[i][k] == 0 || conn[k][j] == 0) continue;
				conn[i][j] = 1;
			}
		}
	}

	int S;
	cin >> S;
	FOR(i, 1, S) {
		int a, b;
		cin >> a >> b;
		if (conn[a][b] == 1)
			cout << -1;
		else if (conn[b][a] == 1)
			cout << 1;
		else
			cout << 0;
		cout << "\n";
	}


	return 0;
}