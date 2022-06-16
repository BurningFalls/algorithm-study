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
	int maxi = 0;
	vector<vector<int>> v(10, vector<int>(10));
	FOR(i, 1, 9) {
		FOR(j, 1, 9) {
			cin >> v[i][j];
			maxi = max(maxi, v[i][j]);
		}
	}
	int y = 1, x = 1;
	FOR(i, 1, 9) {
		FOR(j, 1, 9) {
			if (v[i][j] == maxi) {
				y = i, x = j;
			}
		}
	}
	cout << maxi << "\n";
	cout << y << " " << x;

	return 0;
}