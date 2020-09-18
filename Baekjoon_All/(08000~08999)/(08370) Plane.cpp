#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int n1, k1, n2, k2;
	cin >> n1 >> k1 >> n2 >> k2;
	cout << n1 * k1 + n2 * k2;

	return 0;
}