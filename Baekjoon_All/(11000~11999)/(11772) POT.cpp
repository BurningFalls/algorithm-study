#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	ll sum = 0;
	cin >> N;
	FOR(i, 1, N) {
		ll num;
		ll a, b;
		cin >> num;
		a = num / 10;
		b = num % 10;
		num = pow(a, b);
		sum += num;
	}
	cout << sum;

	return 0;
}