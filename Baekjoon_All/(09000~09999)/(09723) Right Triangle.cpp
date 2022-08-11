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
	int T;
	cin >> T;
	FOR(tc, 1, T) {
		vector<int> v(3);
		FOR(i, 0, 2) {
			cin >> v[i];
		}
		sort(ALL(v));
		cout << "Case #" << tc << ": ";
		cout << (v[0] * v[0] + v[1] * v[1] == v[2] * v[2] ? "YES" : "NO") << "\n";
	}

	return 0;
}