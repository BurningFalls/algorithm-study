#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
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
	int N, K;
	cin >> N >> K;
	vi len(N);
	vvl v(N, vl(21, 0));
	FOR(i, 0, N - 1) {
		string s;
		cin >> s;
		len[i] = LEN(s);
		if (i == 0) {
			v[0][LEN(s)] = 1;
		}
		else {
			FOR(j, 2, 20) {
				if (j == LEN(s)) {
					v[i][j] = v[i - 1][j] + 1;
				}
				else {
					v[i][j] = v[i - 1][j];
				}
			}
		}
	}
	ll ans = 0;
	FOR(left, 0, N - 2) {
		int right = min(N - 1, left + K);
		ans += v[right][len[left]] - v[left][len[left]];
	}
	cout << ans;

	return 0;
}