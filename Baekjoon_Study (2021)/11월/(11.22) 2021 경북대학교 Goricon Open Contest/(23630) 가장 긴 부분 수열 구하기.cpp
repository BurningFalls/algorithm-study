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

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	int cnt[20] = { 0, };
	FOR(i, 0, N - 1) {
		FOR(j, 0, 19) {
			if (v[i] & (1 << j)) {
				cnt[j]++;
			}
		}
	}
	int maxi = 0;
	FOR(i, 0, 19) {
		maxi = max(maxi, cnt[i]);
	}
	cout << maxi;

	return 0;
}