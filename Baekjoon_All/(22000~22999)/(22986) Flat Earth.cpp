#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		ll N, K;
		cin >> N >> K;
		ll left = max(N - K - 1, 0LL);
		ll right = N;
		left = left * (left + 1) / 2;
		right = right * (right + 1) / 2;
		cout << 4 * (right - left) << "\n";
	}


	return 0;
}