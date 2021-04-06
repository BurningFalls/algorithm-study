#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int ans = 0;
	vector<int> v;
	int sum[11] = { 0, };
	FOR(i, 1, 11) {
		int a, b;
		cin >> a >> b;
		v.push_back(a);
		ans += 20 * b;
	}
	sort(v.begin(), v.end());
	FOR(i, 0, 10) {
		ans += (11 - i) * v[i];
	}
	cout << ans;

	return 0;
}