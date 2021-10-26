#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> diff(N);
	FOR(i, 0, N - 1) {
		cin >> diff[i];
	}
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		diff[i] -= num;
	}
	int ans = 0;
	int prev = diff[0];
	FOR(i, 1, N - 1) {
		if (prev * diff[i] < 0) {
			ans += abs(prev);
		}
		else if (abs(prev) > abs(diff[i])) {
			ans += abs(prev - diff[i]);
		}
		prev = diff[i];
	}
	ans += abs(prev);
	cout << ans;

	return 0;
}