#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

vector<ll> v;

int main() {
	FASTIO;
	FOR(i, 1, 10000)
		v.push_back(i * i * i);
	int T;
	cin >> T;
	while (T--) {
		ll x;
		cin >> x;
		bool flag = false;
		FOR(i, 0, 9999) {
			if (x <= v[i]) break;
			flag = binary_search(v.begin(), v.end(), x - v[i]);
			if (flag)
				break;
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}