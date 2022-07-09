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
	int TC;
	cin >> TC;
	while (TC--) {
		int N, T;
		cin >> N >> T;
		vector<int> A(N), B(N), C(N), D(N), E(N + 1);
		FOR(i, 0, N - 1) {
			cin >> A[i] >> B[i] >> C[i] >> D[i];
		}
		FOR(i, 0, N) {
			cin >> E[i];
		}
		bool flag = false;
		int left = 0, right = T;
		while (left <= right) {
			int mid = (left + right) / 2;
			int tim = mid + E[0];
			FOR(i, 0, N - 1) {
				tim = max(tim, C[i]);
				if ((tim - C[i]) % A[i] > B[i] - D[i]) {
					int tmp = (tim - C[i]) / A[i] + 1;
					tim = C[i] + A[i] * tmp;
				}
				tim += D[i];
				tim += E[i + 1];
			}
			if (tim < T) {
				left = mid + 1;
			}
			else if (tim > T) {
				right = mid - 1;
			}
			else if (tim == T) {
				flag = true;
				break;
			}
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}