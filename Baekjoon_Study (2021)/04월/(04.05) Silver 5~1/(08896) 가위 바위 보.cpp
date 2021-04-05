#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[11];
bool alive[11];
vector<int> v[4];

int main() {
	FASTIO;
	int T;
	cin >> T;
	int N;
	while (T--) {
		cin >> N;
		FOR(i, 1, N)
			alive[i] = 1;
		FOR(i, 1, N)
			cin >> arr[i];
		int len = arr[1].size();
		FOR(i, 0, len - 1) {
			FOR(j, 1, 3)
				v[j].clear();
			FOR(j, 1, N) {
				if (!alive[j]) continue;
				if (arr[j][i] == 'S')
					v[1].push_back(j);
				else if (arr[j][i] == 'R')
					v[2].push_back(j);
				else if (arr[j][i] == 'P')
					v[3].push_back(j);
			}
			int len1 = v[1].size();
			int len2 = v[2].size();
			int len3 = v[3].size();
			if (len1 && len2 && !len3) {
				FOR(j, 0, len1 - 1)
					alive[v[1][j]] = 0;
			}
			else if (len1 && !len2 && len3) {
				FOR(j, 0, len3 - 1)
					alive[v[3][j]] = 0;
			}
			else if (!len1 && len2 && len3) {
				FOR(j, 0, len2 - 1)
					alive[v[2][j]] = 0;
			}
		}
		int ans = 0;
		int cnt = 0;
		FOR(i, 1, N) {
			if (alive[i]) {
				ans = i;
				cnt++;
			}
		}
		if (cnt >= 2)
			ans = 0;
		cout << ans << "\n";
	}


	return 0;
}