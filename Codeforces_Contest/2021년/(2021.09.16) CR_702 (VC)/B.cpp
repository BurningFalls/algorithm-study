#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		int cnt[3] = { 0, };
		cin >> N;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			cnt[num % 3]++;
		}
		int tmp = N / 3;
		int ans = 0;
		FOR(i, 0, 4) {
			if (cnt[i % 3] > tmp) {
				int diff = cnt[i % 3] - tmp;
				ans += diff;
				cnt[i % 3] -= diff;
				cnt[(i + 1) % 3] += diff;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}