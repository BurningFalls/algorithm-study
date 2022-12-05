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
	int N, M;
	cin >> N >> M;
	vector<ll> S(N + M, 0);
	FOR(i, 0, N - 1) {
		cin >> S[i];
	}
	FOR(i, 0, N - 1) {
		FOR(j, 0, N + M - 1) {
			ll num;
			cin >> num;
			S[i] -= num;
			S[j] += num;
		}
	}
	FOR(i, 0, N + M - 1) {
		cout << S[i] << " ";
	}

	return 0;
}