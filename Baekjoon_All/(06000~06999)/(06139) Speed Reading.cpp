#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, K) {
		int s, t, r;
		cin >> s >> t >> r;
		int temp;
		if (N % s == 0)
			temp = N / s;
		else
			temp = N / s + 1;
		int x;
		if (temp % t == 0)
			x = temp / t - 1;
		else
			x = temp / t;
		int ans = 0;
		ans += x * (t + r);
		ans += temp - x * t;
		cout << ans << "\n";
	}

	return 0;
}