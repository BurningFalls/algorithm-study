#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll a, b;
	cin >> a >> b;
	ll k = a + b;
	if (b == 0)
		cout << 3 * k * k + 3 * k + 1;
	else
		cout << 3 * k * k - 2 * k + 1 - a;

	return 0;
}