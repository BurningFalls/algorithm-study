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
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(M));
	int zero = 0, one = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> v[i][j];
			zero += (v[i][j] == 0);
			one += (v[i][j] == 1);
		}
	}
	if (zero % 2 == 1 || one % 2 == 1) {
		cout << -1;
	}
	else {
		bool flag = true;
		int z1 = 0, o1 = 0, z2 = 0, o2 = 0;
		FOR(i, 0, N - 1) {
			FOR(j, 0, M - 1) {
				if ((i + j) % 2 == 0) {
					z1 += (v[i][j] == 0);
					o1 += (v[i][j] == 1);
				}
				else if ((i + j) % 2 == 1) {
					z2 += (v[i][j] == 0);
					o2 += (v[i][j] == 1);
				}
			}
		}
		if ((z1 == N * M / 2 && o2 == N * M / 2) ||
			(z2 == N * M / 2 && o1 == N * M / 2)) {
			cout << -1;
		}
		else {
			cout << 1;
		}
	}

	return 0;
}