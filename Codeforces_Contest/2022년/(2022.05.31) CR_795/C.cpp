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
		int N, K;
		string s;
		cin >> N >> K;
		cin >> s;

		int one_cnt = 0;
		FOR(i, 0, LEN(s) - 1) {
			one_cnt += (s[i] - '0');
		}

		if (one_cnt == 0) {
			cout << 0;
		}
		else if (one_cnt == 1) {
			int idx = 0;
			FOR(i, 0, N - 1) {
				if (s[i] == '1') {
					idx = i;
				}
			}

			if (N - 1 - idx <= K) {
				cout << 1;
			}
			else if (idx <= K) {
				cout << 10;
			}
			else {
				cout << 11;
			}
		}
		else if (one_cnt >= 2) {
			int ans = one_cnt * 11;
			int left = 0, right = N - 1;
			while (left < N && s[left] == '0') {
				left++;
			}
			while (right >= 0 && s[right] == '0') {
				right--;
			}

			if (N - 1 - right + left <= K) {
				ans -= 11;
			}
			else if (N - 1 - right <= K) {
				ans -= 10;
			}
			else if (left <= K) {
				ans -= 1;
			}
			cout << ans;
		}
		cout << "\n";
	}

	return 0;
}