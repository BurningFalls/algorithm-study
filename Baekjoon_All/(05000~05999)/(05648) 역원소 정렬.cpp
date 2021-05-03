#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<ll> v;

int main() {
	FASTIO;
	int T;
	cin >> T;
	string s;
	while (T--) {
		cin >> s;
		if (s != "0") {
			while (s.back() == '0')
				s.pop_back();
		}
		reverse(s.begin(), s.end());
		v.push_back(stol(s));
	}
	sort(v.begin(), v.end());
	for (ll x : v)
		cout << x << "\n";

	return 0;
}