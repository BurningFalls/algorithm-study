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

PQ<int> pq[100001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<ll> X(N);
	FOR(i, 0, N - 1) {
		cin >> X[i];
	}
	sort(ALL(X), greater<int>());
	FOR(i, 0, N - 1) {
		if (pq[X[i] + 1].empty()) {
			pq[X[i]].push(X[i]);
		}
		else {
			int num = pq[X[i] + 1].top();
			pq[X[i] + 1].pop();
			pq[X[i]].push(num);
		}
	}
	ll ans = 0;
	FOR(i, 1, 100000) {
		while (!pq[i].empty()) {
			ll node = pq[i].top();
			pq[i].pop();
			ans += node * (node - i + 1);
		}
	}
	cout << ans;

	return 0;
}