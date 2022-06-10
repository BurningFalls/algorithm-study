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
		vector<int> v(N);
		FOR(i, 0, N - 1) {
			cin >> v[i];
		}
		int prev = min(v[0], N - v[0] + 1);
		bool flag = true;
		FOR(i, 1, N - 1) {
			int mini = min(v[i], N - v[i] + 1);
			int maxi = max(v[i], N - v[i] + 1);
			if (prev <= mini) {
				prev = mini;
			}
			else if (mini < prev && prev <= maxi) {
				prev = maxi;
			}
			else if (maxi < prev) {
				flag = false;
				break;
			}
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}