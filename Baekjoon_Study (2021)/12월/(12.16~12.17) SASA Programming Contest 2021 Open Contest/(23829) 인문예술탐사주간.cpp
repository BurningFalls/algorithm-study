#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	vector<ll> P(N);
	vector<ll> Sum(N, 0);
	FOR(i, 0, N - 1) {
		cin >> P[i];
	}
	sort(ALL(P));
	Sum[0] = P[0];
	FOR(i, 1, N - 1) {
		Sum[i] = Sum[i - 1] + P[i];
	}
	FOR(q, 1, Q) {
		ll X;
		cin >> X;
		int ub = upper_bound(ALL(P), X) - P.begin() - 1;
		ll tmp;
		if (ub == -1) {
			tmp = Sum[N - 1] - X * N;
		}
		else {
			tmp = (X * (ub + 1) - Sum[ub]) + (Sum[N - 1] - Sum[ub] - X * (N - 1 - ub));
		}
		cout << tmp << "\n";
	}


	return 0;
}