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
	int N, Q;
	cin >> N >> Q;
	FOR(i, 1, N - 1) {
		int num;
		cin >> num;
	}
	set<int> s;
	int mini = N + 1, maxi = 0;
	bool flag = false;
	FOR(q, 1, Q) {
		int c, v;
		cin >> c >> v;
		if (c == 1) {
			s.insert(v);
			mini = min(mini, v);
			maxi = max(maxi, v);
			flag = true;
		}
		else if (c == 2) {
			if (!flag) {
				cout << -1;
			}
			else {
				if (v <= mini) {
					cout << mini - v;
				}
				else if (maxi < v) {
					cout << v - maxi;
				}
				else {
					auto it = s.lower_bound(v);
					int right = *it;
					it--;
					int left = *it;
					cout << min(right - v, v - left);
				}
			}
			cout << "\n";
		}
	}

	return 0;
}