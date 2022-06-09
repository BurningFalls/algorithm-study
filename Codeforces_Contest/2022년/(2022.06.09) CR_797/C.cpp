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
#define INF int(2e9)
#define LINF ll(1e18)

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> S(N), F(N);
		FOR(i, 0, N - 1) {
			cin >> S[i];
		}
		FOR(i, 0, N - 1) {
			cin >> F[i];
		}
		cout << F[0] - S[0] << " ";
		FOR(i, 1, N - 1) {
			cout << F[i] - max(F[i - 1], S[i]) << " ";
		}
		cout << "\n";
	}

	return 0;
}