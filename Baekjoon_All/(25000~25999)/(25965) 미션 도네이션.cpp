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

struct NODE {
	ll k;
	ll d;
	ll a;
};

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(n, 1, N) {
		int M;
		cin >> M;
		vector<NODE> v(M);
		ll k, d, a;
		FOR(i, 0, M - 1) {
			cin >> v[i].k >> v[i].d >> v[i].a;
		}
		cin >> k >> d >> a;
		ll sum = 0;
		FOR(i, 0, M - 1) {
			ll tmp = k * v[i].k + a * v[i].a - d * v[i].d;
			sum += max(0LL, tmp);
		}
		cout << sum << "\n";
	}

	return 0;
}