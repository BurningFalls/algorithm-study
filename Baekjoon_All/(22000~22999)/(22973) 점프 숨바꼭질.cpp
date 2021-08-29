#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll K;
	cin >> K;
	if (K == 0)
		cout << 0;
	else if (K % 2 == 0)
		cout << -1;
	else {
		int cnt = 0;
		while (K) {
			K /= 2;
			cnt++;
		}
		cout << cnt;
	}

	return 0;
}