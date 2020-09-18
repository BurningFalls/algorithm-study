#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define PI 3.141592
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	double d1, d2;
	cin >> d1 >> d2;
	cout << fixed << setprecision(6);
	cout << 2 * d1 + 2 * d2 * PI;

	return 0;
}