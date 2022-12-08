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
	int N;
	cin >> N;
	vector<pair<double, double>> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i].first >> v[i].second;
	}

	int Q;
	cin >> Q;
	FOR(i, 1, Q) {
		double k;
		cin >> k;
		int left = 0, right = N - 1;
		int pos = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (v[mid].first <= k) {
				pos = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		if (v[pos].second < v[pos + 1].second) {
			cout << 1;
		}
		else if (v[pos].second == v[pos + 1].second) {
			cout << 0;
		}
		else {
			cout << -1;
		}
		cout << "\n";
	}

	return 0;
}