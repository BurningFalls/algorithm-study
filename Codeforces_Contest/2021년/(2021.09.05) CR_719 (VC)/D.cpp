#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

map<int, int> mp;

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		mp.clear();
		int N;
		cin >> N;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			mp[num - i] += 1;
		}
		ll ans = 0;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ll t = (*it).second;
			ans += t * (t - 1) / 2;
		}
		cout << ans << "\n";
	}



	return 0;
}