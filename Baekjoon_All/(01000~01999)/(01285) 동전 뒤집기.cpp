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

void Flip(int y, int N, vector<vector<char>>& v) {
	FOR(i, 0, N - 1) {
		if (v[y][i] == 'H') {
			v[y][i] = 'T';
		}
		else if (v[y][i] == 'T') {
			v[y][i] = 'H';
		}
	}
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<vector<char>> Map(N, vector<char>(N));
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			cin >> Map[i][j];
		}
	}
	int mini = INF;
	FOR(i, 0, (1 << N) - 1) {
		vector<vector<char>> tmp = Map;
		FOR(j, 0, N - 1) {
			if (i & (1 << j)) {
				Flip(j, N, tmp);
			}
		}
		int total_cnt = 0;
		FOR(j, 0, N - 1) {
			int cnt = 0;
			FOR(k, 0, N - 1) {
				if (tmp[k][j] == 'H') {
					cnt++;
				}
			}
			total_cnt += min(cnt, N - cnt);
		}
		mini = min(mini, total_cnt);
	}
	cout << mini;

	return 0;
}