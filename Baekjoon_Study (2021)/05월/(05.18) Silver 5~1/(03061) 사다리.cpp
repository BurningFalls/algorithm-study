#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int pos[1001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			pos[num] = i;
		}
		int ans = 0;
		FOR(i, 1, N) {
			ans += pos[i] - i;
			if (ans == 0) continue;
			FOR(j, i + 1, N) {
				if (pos[j] < pos[i])
					pos[j] += 1;
			}
			pos[i] = i;
		}
		cout << ans << "\n";
	}

	return 0;
}