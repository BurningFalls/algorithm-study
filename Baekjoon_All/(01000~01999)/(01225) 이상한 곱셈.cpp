#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	string a, b;
	ll ans = 0;
	cin >> a >> b;
	int a_len = a.size();
	int b_len = b.size();
	FOR(i, 0, a_len - 1) {
		FOR(j, 0, b_len - 1) {
			ans += ((ll)a[i] - '0') * ((ll)b[j] - '0');
		}
	}
	cout << ans;

	return 0;
}