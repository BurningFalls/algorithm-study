#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

vector<int> pos[200001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N)
			pos[i].clear();
		FOR(i, 1, N) {
			int num;
			cin >> num;
			pos[num].push_back(i);
		}
		int ans = 987654321;
		FOR(i, 1, N) {
			if (pos[i].empty()) continue;
			int cnt = 0;
			int prev = 0;
			FOR(j, 0, LEN(pos[i]) - 1) {
				if (prev + 1 != pos[i][j])
					cnt++;
				prev = pos[i][j];
			}
			if (prev + 1 != N + 1)
				cnt++;
			ans = min(ans, cnt);
		}
		cout << ans << "\n";
	}

	return 0;
}