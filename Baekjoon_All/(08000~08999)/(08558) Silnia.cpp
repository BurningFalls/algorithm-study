#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int n;
	int x = 1;
	cin >> n;
	FOR(i, 1, n) {
		x = (x * i) % 10;
	}
	cout << x;

	return 0;
}