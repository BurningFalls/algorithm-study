#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000009

int main() {
	FASTIO;
	int N;
	cin >> N;
	ll cnt = 2;
	int idx = 2;
	while (idx < N) {
		cnt = (cnt * 3) % MOD;
		idx++;
	}
	if (N == 1)
		cout << 0;
	else {
		cout << cnt;
	}

	return 0;
}