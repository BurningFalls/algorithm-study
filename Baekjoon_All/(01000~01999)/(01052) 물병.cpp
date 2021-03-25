#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	int ans = 0;
	while (true) {
		int cnt = 0;
		FOR(i, 0, 23) {
			if (N & (1 << i))
				cnt++;
		}
		if (cnt <= K)
			break;
		N += 1;
		ans += 1;
	}
	cout << ans;

	return 0;
}