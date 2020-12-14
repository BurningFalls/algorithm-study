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
	while (true) {
		int div = 1;
		ll ans = 1;
		cin >> N >> K;
		if (N == 0 && K == 0)
			break;
		if (N - K < K)
			K = N - K;
		while (K--) {
			ans *= N;
			N--;
			ans /= div;
			div++;
		}
		cout << ans << "\n";
	}

	return 0;
}