#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int N, M;
	vector<vector<char>> Map(51, vector<char>(51));
	cin >> N >> M;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 0, N - 1) {
		FOR(j, 0, M / 2 - 1) {
			if (Map[i][j] == '.' && Map[i][M - 1 - j] == '.') continue;
			if (Map[i][j] != '.') {
				Map[i][M - 1 - j] = Map[i][j];
			}
			else if (Map[i][M - 1 - j] != '.') {
				Map[i][j] = Map[i][M - 1 - j];
			}
		}
	}
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cout << Map[i][j];
		}
		cout << "\n";
	}


	return 0;
}