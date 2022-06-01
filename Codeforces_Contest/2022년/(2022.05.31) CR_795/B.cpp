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
		map<int, int> mp;
		vector<int> v(N + 1);
		vector<int> ans(N + 1, -1);
		FOR(i, 1, N) {
			cin >> v[i];
			if (mp.count(v[i])) {
				ans[i] = mp[v[i]];
			}
			mp[v[i]] = i;
		}

		bool flag = true;
		FOR(i, 1, N) {
			if (ans[i] != -1) continue;
			if (mp[v[i]] == i) {
				flag = false;
				break;
			}
			ans[i] = mp[v[i]];
		}

		if (flag) {
			FOR(i, 1, N) {
				cout << ans[i] << " ";
			}
		}
		else if (!flag) {
			cout << -1;
		}
		cout << "\n";
	}

	return 0;
}