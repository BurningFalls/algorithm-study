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
	if (a % 2 == 0 || b % 2 == 0)
		cout << 0;
	else
		cout << min(a, b);


	return 0;
}