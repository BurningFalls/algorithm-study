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
	vector<int> v(N);
	vector<int> ans(N, 0);
	map<int, int> mp;
	FOR(i, 0, N - 1) {
		cin >> v[i];
		mp[v[i]] = i;
	}
	sort(ALL(v));
	FOR(i, 0, N - 1) {
		int sqrtn = sqrt(v[i]);
		for (int j = 1; j <= sqrtn; j++) {
			if (v[i] % j != 0) continue;
			int a = j;
			int b = v[i] / j;
			if (mp.count(a)) {
				ans[mp[v[i]]]--;
				ans[mp[a]]++;
			}
			if (b != a && mp.count(b)) {
				ans[mp[v[i]]]--;
				ans[mp[b]]++;
			}
		}
	}

	FOR(i, 0, N - 1) {
		cout << ans[i] << " ";
	}

	return 0;
}