#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<vector<char>> v(N, vector<char>(M));
		int one_cnt = 0;
		vector<int> dy = { -1, 1, 0, 0 };
		vector<int> dx = { 0, 0, -1, 1 };
		FOR(i, 0, N - 1) {
			FOR(j, 0, M - 1) {
				cin >> v[i][j];
				one_cnt += (v[i][j] == '1');
			}
		}
		if (one_cnt == 0) {
			cout << 0;
		}
		else if (one_cnt == 1) {
			cout << 1;
		}
		else if (one_cnt == N * M) {
			cout << N * M - 2;
		}
		else {
			bool flag = false;
			FOR(i, 0, N - 2) {
				FOR(j, 0, M - 2) {
					int tmp = 8 * (v[i][j] - '0') + 4 * (v[i][j + 1] - '0') + 2 * (v[i + 1][j] - '0') + 1 * (v[i + 1][j + 1] - '0');
					flag |= ((1 <= tmp && tmp <= 6) || (8 <= tmp && tmp <= 10) || tmp == 12);
				}
			}
			cout << (flag ? one_cnt : one_cnt - 1);
		}
		cout << "\n";
	}

	return 0;
}