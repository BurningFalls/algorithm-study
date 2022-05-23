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
		int N;
		string s;
		cin >> N;
		cin >> s;

		char x = s[(N - 1) / 2];
		int left = (N - 1) / 2;
		int right = (N - 1) / 2;
		int cnt = 0;
		while(left >= 0 && s[left] == x) {
			left--;
			cnt++;
		}
		while (right < N && s[right] == x) {
			right++;
			cnt++;
		}
		cout << cnt - 1 << "\n";
	}

	return 0;
}