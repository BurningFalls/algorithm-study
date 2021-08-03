#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	double A, D, K;
	cin >> A >> D >> K;
	D /= 100;
	K /= 100;
	double a = A, d = 1, k = D;
	double ans = 0;
	while (k < 1) {
		ans += a * d * k;
		a += A;
		d *= (1 - k);
		k *= (1 + K);
	}
	k = 1;
	ans += a * d * k;
	cout << fixed << setprecision(6);
	cout << ans;


	return 0;
}