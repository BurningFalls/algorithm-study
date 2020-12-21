#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	int ans = 0;
	cin >> N;
	FOR(i, 1, N - 2) {
		if (i % 2 == 1) continue;
		FOR(j, 1, N - 2) {
			int k = N - i - j;
			if (k - j < 2) continue;
			ans++;
		}
	}
	cout << ans;

	return 0;
}