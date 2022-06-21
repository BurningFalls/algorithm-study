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
	vector<vector<int>> v(2, vector<int>(5));
	vector<int> ans(2);
	FOR(i, 0, 1) {
		FOR(j, 0, 4) {
			cin >> v[i][j];
		}
	}
	FOR(i, 0, 1) {
		ans[i] = 6 * v[i][0] + 3 * v[i][1] + 2 * v[i][2] + 1 * v[i][3] + 2 * v[i][4];
	}
	FOR(i, 0, 1) {
		cout << ans[i] << " ";
	}

	return 0;
}