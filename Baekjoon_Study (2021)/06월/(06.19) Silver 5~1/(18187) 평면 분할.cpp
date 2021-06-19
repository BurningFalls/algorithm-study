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
	int ans = 1;
	int idx = 1;
	cin >> N;
	FOR(i, 1, N) {
		ans += idx;
		if (i % 3 != 0)
			idx++;
	}
	cout << ans;


	return 0;
}