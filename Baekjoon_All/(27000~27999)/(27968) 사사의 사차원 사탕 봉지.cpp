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
	ll N, M;
	cin >> N >> M;
	vector<ll> A(M), B(N);
	FOR(i, 0, M - 1) {
		cin >> A[i];
		if (i != 0) {
			A[i] += A[i - 1];
		}
	}
	FOR(i, 0, N - 1) {
		cin >> B[i];
	}
	FOR(i, 0, N - 1) {
		int lb = lower_bound(ALL(A), B[i]) - A.begin();
		lb += 1;
		if (lb > M) {
			cout << "Go away!";
		}
		else {
			cout << lb;
		}
		cout << "\n";
	}

	return 0;
}