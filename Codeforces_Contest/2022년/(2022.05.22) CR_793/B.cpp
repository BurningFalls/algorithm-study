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
#define INF int(2e9)
#define LINF ll(1e18)

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> p(N);
		FOR(i, 0, N - 1) {
			cin >> p[i];
		}

		vector<int> v;
		FOR(i, 0, N - 1) {
			if (i != p[i]) {
				v.push_back(p[i]);
			}
		}
		int ans = v[0] & v[1];
		FOR(i, 2, LEN(v) - 1) {
			ans = ans & v[i];
		}
		cout << ans << "\n";
	}

	return 0;
}