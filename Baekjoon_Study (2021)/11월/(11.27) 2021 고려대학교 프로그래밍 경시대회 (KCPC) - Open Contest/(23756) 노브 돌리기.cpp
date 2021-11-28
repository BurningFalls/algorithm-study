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
	vector<int> A(N + 1);
	cin >> A[0];
	FOR(i, 1, N) {
		cin >> A[i];
	}
	int ans = 0;
	FOR(i, 0, N - 1) {
		int diff = abs(A[i] - A[i + 1]);
		ans += min(diff, 360 - diff);
	}
	cout << ans;

	return 0;
}