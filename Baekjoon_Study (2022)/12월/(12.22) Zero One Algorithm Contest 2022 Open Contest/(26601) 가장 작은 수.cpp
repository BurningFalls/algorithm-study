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
#define MOD 2000003
#define MAX 1500000

vector<int> is_prime(MAX + 1, 1);
vector<int> num(MAX + 1);

void Find_Prime() {
	FOR(i, 1, MAX) {
		num[i] = i;
	}
	int sqrtn = sqrt(MAX);
	FOR(i, 2, sqrtn) {
		if (!is_prime[i]) continue;
		for (int j = i * 2; j <= MAX; j += i) {
			is_prime[j] = 0;
			num[j] = min(num[j], i);
		}
	}
}

int main() {
	FASTIO;
	Find_Prime();
	vector<ll> v;
	FOR(i, 2, MAX) {
		map<int, int> mp;
		int n = i;
		while (n != 1) {
			mp[num[n]]++;
			n /= num[n];
		}
		if (LEN(mp) == 1) {
			int m = (*mp.begin()).second;
			while (m != 1 && m % 2 == 0) {
				m /= 2;
			}
			if (m == 1) {
				v.push_back(i);
			}
		}
	}

	ll N;
	cin >> N;
	ll ans = 1;
	FOR(i, 0, N - 1) {
		ans = (ans * v[i]) % MOD;
	}
	cout << ans;

	return 0;
}