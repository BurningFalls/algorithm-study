#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	double a, b, c;
	cin >> a >> b >> c;
	cout << floor((a + 1) * (b + 1) / (c + 1) - 1);

	return 0;
}