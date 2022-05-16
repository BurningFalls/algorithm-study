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
	int N, M;
	cin >> N >> M;
	vector<int> A(1001, 0), B(1001, 0);
	FOR(i, 1, N) {
		cin >> A[i];
	}
	FOR(i, 1, M) {
		cin >> B[i];
	}

	int maxi = 0;
	FOR(i, 1, max(N, M)) {
		maxi = max(maxi, B[i] - A[i]);
	}
	cout << maxi;

	return 0;
}