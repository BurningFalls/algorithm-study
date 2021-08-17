#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll X1, Y1, R1;
	ll X2, Y2, R2;
	cin >> X1 >> Y1 >> R1;
	cin >> X2 >> Y2 >> R2;
	ll dist = (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2);
	if (dist < (R1 + R2) * (R1 + R2))
		cout << "YES";
	else
		cout << "NO";


	return 0;
}