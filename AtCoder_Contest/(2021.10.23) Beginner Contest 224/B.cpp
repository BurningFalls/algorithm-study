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

int main() {
	FASTIO;
	int H, W;
	cin >> H >> W;
	int A[51][51];
	FOR(i, 1, H) {
		FOR(j, 1, W) {
			cin >> A[i][j];
		}
	}
	bool flag = true;
	FOR(i1, 1, H) {
		FOR(i2, i1 + 1, H) {
			FOR(j1, 1, W) {
				FOR(j2, j1 + 1, W) {
					if (A[i1][j1] + A[i2][j2] > A[i2][j1] + A[i1][j2]) {
						flag = false;
					}
				}
			}
		}
	}
	cout << (flag ? "Yes" : "No");


	return 0;
}