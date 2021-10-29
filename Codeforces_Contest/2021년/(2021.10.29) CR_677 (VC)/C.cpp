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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> v(N);
		int maxi = 0;
		int cnt = 0;
		int idx = 0;
		FOR(i, 0, N - 1) {
			cin >> v[i];
			maxi = max(maxi, v[i]);
		}
		FOR(i, 0, N - 1) {
			if (maxi == v[i]) {
				cnt++;
				if (i == 0) {
					if (v[i + 1] == maxi) continue;
					idx = i + 1;
				}
				else if (i == N - 1) {
					if (v[i - 1] == maxi) continue;
					idx = i + 1;
				}
				else {
					if (v[i - 1] == maxi && v[i + 1] == maxi) continue;
					idx = i + 1;
				}
			}
		}
		cout << (cnt != N ? idx : -1) << "\n";
	}


	return 0;
}