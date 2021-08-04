#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<int, int> mp1, mp2;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		mp1[a]++;
		mp2[b]++;
	}
	int ans = 0;
	for (auto it = mp1.begin(); it != mp1.end(); it++) {
		if ((*it).second >= 2) {
			ans++;
		}
	}
	for (auto it = mp2.begin(); it != mp2.end(); it++) {
		if ((*it).second >= 2) {
			ans++;
		}
	}
	cout << ans;

	return 0;
}