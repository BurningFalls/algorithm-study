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
		int N, M;
		cin >> N >> M;
		vector<int> sum(N, 0);
		FOR(i, 0, M - 1) {
			FOR(j, 0, N - 1) {
				int num;
				cin >> num;
				sum[j] += num;
			}
		}
		vector<pii> v;
		FOR(i, 0, N - 1) {
			v.push_back({ sum[i], i });
		}
		sort(ALL(v));
		cout << v[N - 1].second + 1 << "\n";
	}

	return 0;
}