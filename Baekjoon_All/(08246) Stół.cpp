#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << (a / c) * (b / c) - max(ll(0), a / c - 2) * max(ll(0), b / c - 2);

	return 0;
}