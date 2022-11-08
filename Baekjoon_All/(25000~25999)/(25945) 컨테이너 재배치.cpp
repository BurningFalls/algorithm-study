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

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<ll> v(N);
	ll sum = 0;
	FOR(i, 0, N - 1) {
		cin >> v[i];
		sum += v[i];
	}
	sort(ALL(v));
	ll diff = 0;
	FOR(i, 0, N - sum % N - 1) {
		diff += abs(sum / N - v[i]);
	}
	FOR(i, N - sum % N, N - 1) {
		diff += abs(sum / N + 1 - v[i]);
	}
	cout << diff / 2;

	return 0;
}