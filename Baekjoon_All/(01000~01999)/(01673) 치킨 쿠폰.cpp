#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int N, K;
	while (cin >> N >> K) {
		int ans = N;
		int cnt = N;
		while (cnt >= K) {
			int temp = cnt / K;
			ans += temp;
			cnt -= temp * K;
			cnt += temp;
		}
		cout << ans << "\n";
	}

	return 0;
}