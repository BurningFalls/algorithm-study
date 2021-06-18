#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main() {
	FASTIO;
	int N;
	ll arr[16];
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	ll up = 1;
	ll down = arr[N];
	ROF(i, N - 1, 1) {
		up = arr[i] * down + up;
		swap(up, down);
	}
	up = down - up;
	ll gcd = GCD(up, down);
	up /= gcd;
	down /= gcd;
	cout << up << " " << down;

	return 0;
}