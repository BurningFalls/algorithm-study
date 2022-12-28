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
	FOR(t, 1, T) {
		int N; double F;
		string s;
		cin >> N >> F;
		cin >> s;
		vector<vector<double>> cnt(N + 1, vector<double>(2, 0));
		double diff = 10;
		int idx = 0;
		FOR(i, 0, N - 1) {
			cnt[i + 1][0] = cnt[i][0] + (s[i] == '0');
			cnt[i + 1][1] = cnt[i][1] + (s[i] == '1');
		}
		FOR(i, 1, N) {
			FOR(j, i, N) {
				double zero = cnt[j][0] - cnt[i - 1][0];
				double one = cnt[j][1] - cnt[i - 1][1];
				double tmp = one / (zero + one);
				if (diff > fabs(tmp - F)) {
					diff = fabs(tmp - F);
					idx = i - 1;
				}
			}
		}
		cout << "Case #" << t << ": ";
		cout << idx << "\n";
	}

	return 0;
}