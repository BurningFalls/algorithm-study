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
	int N;
	cin >> N;
	vector<ll> A(N);
	ll maxi = 0;
	FOR(i, 0, N - 1) {
		cin >> A[i];
		maxi = max(maxi, A[i]);
	}
	FOR(i, 1, N - 2) {
		maxi = max(maxi, A[i] + min(A[i - 1], A[i + 1]));
	}
	cout << maxi;

	return 0;
}