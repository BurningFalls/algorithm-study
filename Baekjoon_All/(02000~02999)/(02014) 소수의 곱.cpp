#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll prime[101];
set<ll> s;

int main() {
	FASTIO;
	int K, N;
	cin >> K >> N;
	FOR(i, 1, K) {
		cin >> prime[i];
		s.insert(prime[i]);
	}
	FOR(i, 1, N - 1) {
		ll node = *(s.begin());
		s.erase(s.begin());
		FOR(j, 1, K) {
			ll nn = node * prime[j];
			s.insert(nn);
			if (s.size() > N)
				s.erase(--s.end());
		}
	}
	cout << *(s.begin());

	return 0;
}