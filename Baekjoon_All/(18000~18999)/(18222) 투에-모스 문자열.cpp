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
	ll cnt = 0;
	int one_cnt = 0;
	ll k = K;
	while (k != 0) {
		if (k % 2 == 1)
			one_cnt++;
		k /= 2;
		cnt++;
	}
	int tmp = 0;
	FOR(i, 0, cnt) {
		if (K & (1LL << i)) {
			tmp = i;
			break;
		}
	}
	if (tmp % 2 == 1) {
		if (one_cnt % 2 == 0)
			cout << 0;
		else if (one_cnt % 2 == 1)
			cout << 1;
	}
	else if (tmp % 2 == 0) {
		if (one_cnt % 2 == 0)
			cout << 1;
		else if (one_cnt % 2 == 1)
			cout << 0;
	}

	return 0;
}