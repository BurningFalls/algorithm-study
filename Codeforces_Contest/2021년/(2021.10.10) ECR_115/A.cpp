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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<vector<char>> v(2, vector<char>(N));
		FOR(i, 0, 1) {
			FOR(j, 0, N - 1) {
				cin >> v[i][j];
			}
		}
		bool flag = true;
		FOR(i, 0, N - 1) {
			if (v[0][i] == '1' && v[1][i] == '1') {
				flag = false;
				break;
			}
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}


	return 0;
}