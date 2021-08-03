#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	int Map[65][65];
	bool possible[65][65] = { 0, };
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	possible[1][1] = 1;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (i == N && j == N) continue;
			if (!possible[i][j]) continue;
			if (j + Map[i][j] <= N)
				possible[i][j + Map[i][j]] = 1;
			if (i + Map[i][j] <= N)
				possible[i + Map[i][j]][j] = 1;
		}
	}
	cout << (possible[N][N] ? "HaruHaru" : "Hing");


	return 0;
}