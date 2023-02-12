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
vector<int> primes;

void Find_Prime() {
	FOR(i, 2, 1000) {
		if (!is_prime[i]) continue;
		if (i != 2) {
			primes.push_back(i);
		}
		for (int j = i * i; j <= 1000000; j += i) {
			is_prime[j] = 0;
		}
	}
	FOR(i, 1001, 1000000) {
		if (!is_prime[i]) continue;
		primes.push_back(i);
	}
}

int main() {
	FASTIO;
	Find_Prime();
	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;
		FOR(i, 0, LEN(primes) - 1) {
			int a = primes[i];
			int b = N - primes[i];
			if (a > b) break;
			if (!is_prime[b]) continue;
			cout << N << " = ";
			cout << a << " + " << b << "\n";
			break;
		}
	}

	return 0;
}