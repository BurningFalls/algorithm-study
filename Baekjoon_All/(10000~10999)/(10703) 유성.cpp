#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char Map[3001][3001];
int near_land[3001][3001] = { 0, };

int main() {
	FASTIO;
	int R, S;
	cin >> R >> S;
	FOR(i, 1, R) {
		FOR(j, 1, S) {
			cin >> Map[i][j];
		}
	}

	FOR(i, 1, S) {
		int land = -1;
		ROF(j, R, 1) {
			if (Map[j][i] == '#')
				land = j;
			else if (Map[j][i] == 'X') {
				near_land[j][i] = land;
			}
		}
	}

	int min_dist = 3003;

	FOR(i, 1, R) {
		FOR(j, 1, S) {
			if (Map[i][j] == 'X') {
				min_dist = min(min_dist, near_land[i][j] - i - 1);
			}
		}
	}

	ROF(i, R, 1) {
		FOR(j, 1, S) {
			if (Map[i][j] == 'X') {
				Map[i + min_dist][j] = 'X';
				Map[i][j] = '.';
			}
		}
	}

	FOR(i, 1, R) {
		FOR(j, 1, S) {
			cout << Map[i][j];
		}
		cout << "\n";
	}

	return 0;
}