#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll N;
	cin >> N;
	ll first = N * N + (N - 1) * N * (N + 1) / 6;
	ll second;
	if (N % 2 == 1) {
		ll tmp = (N - 1) / 2 - 1;
		second = tmp * (tmp + 1) * (4 * tmp + 5) / 6;
	}
	else if (N % 2 == 0) {
		ll tmp = N / 2 - 1;
		second = tmp * (tmp + 1) * (4 * tmp - 1) / 6;
	}
	cout << first + second;


	return 0;
}