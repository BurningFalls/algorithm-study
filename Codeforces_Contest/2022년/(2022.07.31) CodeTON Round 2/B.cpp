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
	int T;
	cin >> T;
	while (T--) {
		int N, X;
		cin >> N >> X;
		vector<int> A(N);
		FOR(i, 0, N - 1) {
			cin >> A[i];
		}
		int left = A[0] - X, right = A[0] + X;
		int cnt = 0;
		FOR(i, 1, N - 1) {
			int l = A[i] - X, r = A[i] + X;
			if (right < l || r < left) {
				cnt++;
				left = l, right = r;
			}
			else {
				left = max(left, l);
				right = min(right, r);
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}