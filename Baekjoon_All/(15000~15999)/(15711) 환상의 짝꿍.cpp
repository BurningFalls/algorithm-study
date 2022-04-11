#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define LIMIT 1414214

vector<bool> is_prime(LIMIT + 1, 1);
vector<ll> primes;

void Find_Prime() {
	is_prime[0] = 0;
	is_prime[1] = 0;
	for(ll i = 2; i <= LIMIT; i++) {
		if (!is_prime[i]) continue;
		primes.push_back(i);
		for (ll j = i * 2; j <= LIMIT; j += i) {
			is_prime[j] = 0;
		}
	}
}

bool is_Prime(ll x) {
	if (x > LIMIT) {
		for (ll p : primes) {
			if (p > x) break;
			if (x % p == 0) {
				return false;
			}
		}
		return true;
	}
	else if (x <= LIMIT) {
		return is_prime[x];
	}
}

int main() {
	FASTIO;
	Find_Prime();
	int T;
	cin >> T;
	while (T--) {
		ll A, B;
		cin >> A >> B;
		if (A + B < 4) {
			cout << "NO";
		}
		else if ((A + B) % 2 == 0) {
			cout << "YES";
		}
		else if ((A + B) % 2 == 1) {
			cout << (is_Prime(A + B - 2) ? "YES" : "NO");
		}
		cout << "\n";
	}

	return 0;
}