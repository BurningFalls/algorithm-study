#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

vector<int> is_prime(1000001, 1);
vector<ll> primes;

void Find_Prime() {
	FOR(i, 2, 1000) {
		if (!is_prime[i]) continue;
		for (int j = i * i; j <= 1000000; j += i) {
			is_prime[j] = 0;
		}
	}
	FOR(i, 2, 1000000) {
		if (!is_prime[i]) continue;
		primes.push_back(i);
	}
}

int main() {
	FASTIO;
	Find_Prime();
	ll a, b;
	cin >> a >> b;
	vector<ll> A, B;
	int idx = 0;
	while ((idx < LEN(primes)) && (a != 1)) {
		while ((a != 1) && (a % primes[idx] == 0)) {
			a /= primes[idx];
			A.push_back(primes[idx]);
		}
		idx++;
	}
	if (a != 1) {
		A.push_back(a);
	}

	idx = 0;
	while ((idx < LEN(primes)) && (b != 1)) {
		while ((b != 1) && (b % primes[idx] == 0)) {
			b /= primes[idx];
			B.push_back(primes[idx]);
		}
		idx++;
	}
	if (b != 1) {
		B.push_back(b);
	}

	ll ans = 1;
	FOR(i, 1, min(LEN(A), LEN(B))) {
		if (A[LEN(A) - i] == B[LEN(B) - i]) {
			ans *= A[LEN(A) - i];
		}
		else {
			break;
		}
	}
	cout << ans;

	return 0;
}