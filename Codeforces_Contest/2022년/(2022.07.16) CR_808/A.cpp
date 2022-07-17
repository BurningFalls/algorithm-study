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
		int N;
		cin >> N;
		vector<int> A(N);
		FOR(i, 0, N - 1) {
			cin >> A[i];
		}
		bool flag = true;
		FOR(i, 1, N - 1) {
			if (A[i] % A[0] != 0) {
				flag = false;
			}
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}