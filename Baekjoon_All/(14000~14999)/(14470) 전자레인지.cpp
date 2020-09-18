#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;
	if (A > 0)
		cout << E * (B - A);
	else if (A == 0)
		cout << D + E * (B - A);
	else if (A < 0)
		cout << C * (0 - A) + D + E * (B - 0);

	return 0;
}