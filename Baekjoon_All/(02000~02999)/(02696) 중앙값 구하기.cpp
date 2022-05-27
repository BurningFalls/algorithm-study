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
		PQ<int> pq1;
		PQ<int, vector<int>, greater<int>> pq2;
		vector<int> ans;
		int M;
		cin >> M;
		FOR(i, 1, M) {
			int num;
			cin >> num;
			if (pq1.empty() || pq1.top() >= num) {
				pq1.push(num);
			}
			else {
				pq2.push(num);
			}
			if (LEN(pq1) < LEN(pq2)) {
				pq1.push(pq2.top());
				pq2.pop();
			}
			if (LEN(pq1) > LEN(pq2) + 1) {
				pq2.push(pq1.top());
				pq1.pop();
			}
			if (i % 2 == 1) {
				ans.push_back(pq1.top());
			}
		}
		cout << LEN(ans) << "\n";
		FOR(i, 0, LEN(ans) - 1) {
			cout << ans[i] << " ";
			if (i % 10 == 9) {
				cout << "\n";
			}
		}
		if ((LEN(ans) - 1) % 10 != 9) {
			cout << "\n";
		}
	}

	return 0;
}