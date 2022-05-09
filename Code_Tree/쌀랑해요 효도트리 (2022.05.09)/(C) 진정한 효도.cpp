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

int Calc(int a, int b, int c) {
	int x = abs(a - b) + abs(a - c);
	int y = abs(b - a) + abs(b - c);
	int z = abs(c - a) + abs(c - b);
	return min({ x, y, z });
}

int main() {
	FASTIO;
	vector<vector<int>> v(3, vector<int>(3));
	FOR(i, 0, 2) {
		FOR(j, 0, 2) {
			cin >> v[i][j];
		}
	}

	int ans = INF;
	FOR(i, 0, 2) {
		ans = min(ans, Calc(v[i][0], v[i][1], v[i][2]));
		ans = min(ans, Calc(v[0][i], v[1][i], v[2][i]));
	}
	cout << ans;


	return 0;
}