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
		int left = 0, right = K - 1;
		int cnt = 0;
		FOR(i, 0, K - 1) {
			cnt += (s[i] == 'W');
		}
		int mini = cnt;
		while (right < N - 1) {
			cnt -= (s[left] == 'W');
			left++;
			right++;
			cnt += (s[right] == 'W');
			mini = min(mini, cnt);
		}
		cout << mini << "\n";
	}

	return 0;
}