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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> v(N);
		FOR(i, 0, N - 1) {
			cin >> v[i];
		}
		int left = 0, right = N - 1;
		while (left <= N - 1 && v[left] == 0) {
			left++;
		}
		while (right >= 0 && v[right] == 0) {
			right--;
		}
		int ans = 0;
		int cnt = 0;
		FOR(i, left, right) {
			if (v[i] == 1) {
				ans += cnt;
				cnt = 0;
			}
			else if (v[i] == 0) {
				cnt++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}