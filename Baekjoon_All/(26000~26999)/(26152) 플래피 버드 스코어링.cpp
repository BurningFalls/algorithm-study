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
	vector<int> A(N), B(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	FOR(i, 0, N - 1) {
		cin >> B[i];
	}

	vector<int> diff(N);
	FOR(i, 0, N - 1) {
		diff[i] = A[i] - B[i];
		if (i != 0) {
			diff[i] = min(diff[i], diff[i - 1]);
		}
	}

	int Q;
	cin >> Q;
	FOR(i, 1, Q) {
		int w;
		cin >> w;
		int left = 0, right = N - 1;
		int ans = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (diff[mid] >= w) {
				left = mid + 1;
				ans = max(ans, left);
			}
			else {
				right = mid - 1;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}