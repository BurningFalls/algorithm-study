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
	vector<int> cnt(N + 1, 0);
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			int num;
			cin >> num;
			cnt[i] += num;
		}
	}
	int L1, L2, R1, R2;
	cin >> L1 >> R1;
	cin >> L2 >> R2;
	FOR(i, L1, R1) {
		cnt[i] = max(0, cnt[i] - 1);
	}
	FOR(i, L2, R2) {
		cnt[i] = max(0, cnt[i] - 1);
	}
	int sum = 0;
	FOR(i, 1, N) {
		sum += cnt[i];
	}
	cout << sum;

	return 0;
}