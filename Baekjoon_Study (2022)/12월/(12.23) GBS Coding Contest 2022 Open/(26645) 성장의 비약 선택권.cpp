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
	vector<int> v(4);
	v[0] = min(210, N + 8);
	v[1] = min(220, N + 4);
	v[2] = min(230, N + 2);
	v[3] = N + 1;
	int maxi = 0;
	FOR(i, 0, 3) {
		maxi = max(maxi, v[i]);
	}
	int idx = 0;
	FOR(i, 0, 3) {
		if (maxi == v[i]) {
			idx = i + 1;
		}
	}
	cout << idx;
	

	return 0;
}