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
	int N;
	cin >> N;
	vector<vector<int>> v(N + 1, vector<int>(6));
	FOR(i, 1, N) {
		FOR(j, 1, 5) {
			cin >> v[i][j];
		}
	}
	vector<int> cnt(N + 1, 0);
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			bool flag = false;
			FOR(k, 1, 5) {
				flag |= (v[i][k] == v[j][k]);
			}
			if (flag) {
				cnt[i]++;
				cnt[j]++;
			}
		}
	}
	int maxi = 0;
	int max_idx = 1;
	FOR(i, 1, N) {
		if (maxi < cnt[i]) {
			maxi = cnt[i];
			max_idx = i;
		}
	}
	cout << max_idx;

	return 0;
}