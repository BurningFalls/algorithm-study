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
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		vector<vector<char>> Map(8, vector<char>(8));
		FOR(i, 0, 7) {
			FOR(j, 0, 7) {
				cin >> Map[i][j];
			}
		}

		int dy[4] = { -1, -1, 1, 1 };
		int dx[4] = { -1 ,1, -1, 1 };
		pii ans = { -1, -1 };
		FOR(i, 1, 6) {
			FOR(j, 1, 6) {
				if (Map[i][j] != '#') continue;
				bool flag = true;
				FOR(k, 0, 3) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (Map[ny][nx] != '#') {
						flag = false;
						break;
					}
				}
				if (flag) {
					ans = { i + 1, j + 1 };
					break;
				}
			}
		}
		cout << ans.first << " " << ans.second << "\n";
	}

	return 0;
}