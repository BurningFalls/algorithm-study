#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int cnt[200001];
int idx[200001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		MEMSET(cnt, 0);
		int N;
		cin >> N;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			cnt[num]++;
			idx[num] = i;
		}
		int ans = -1;
		FOR(i, 1, N) {
			if (cnt[i] == 1) {
				ans = idx[i];
				break;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}