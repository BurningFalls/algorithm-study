#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((a * c) % (b * d * 2) == 0)
		cout << 1;
	else
		cout << 0;

	return 0;
}