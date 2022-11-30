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
	vector<ll> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	sort(ALL(A));
	FOR(m, 0, M - 1) {
		ll kind, a, b;
		cin >> kind;
		if (kind == 1) {
			cin >> a;
			if (a > A[N - 1]) {
				cout << 0;
			}
			else {
				int lb = lower_bound(ALL(A), a) - A.begin();
				cout << N - lb;
			}
		}
		else if (kind == 2) {
			cin >> a;
			if (a >= A[N - 1]) {
				cout << 0;
			}
			else {
				int ub = upper_bound(ALL(A), a) - A.begin();
				cout << N - ub;
			}
		}
		else if (kind == 3) {
			cin >> a >> b;
			if (a > A[N - 1]) {
				cout << 0;
			}
			else {
				int lb = lower_bound(ALL(A), a) - A.begin();
				if (b >= A[N - 1]) {
					cout << N - lb;
				}
				else {
					int ub = upper_bound(ALL(A), b) - A.begin();
					cout << ub - lb;
				}
			}
		}
		cout << "\n";
	}


	return 0;
}