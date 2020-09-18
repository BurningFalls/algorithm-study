#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll A[250001];

int main() {
	FASTIO;
	ll N, Q;
	cin >> N >> Q;
	ROF(i, N, 1)
		cin >> A[i];
	FOR(i, 1, Q) {
		ll x, y;
		cin >> x >> y;
		ll temp1 = A[(N + 1) - y] - (x - 1);
		int lb = lower_bound(A + 1, A + (N + 2 - y), x) - A;
		ll temp2 = ((N - y + 1) - lb + 1);
		if (temp1 <= 0)
			cout << 0;
		else
			cout << temp1 + temp2 - 1;
		cout << "\n";
	}

	return 0;
}