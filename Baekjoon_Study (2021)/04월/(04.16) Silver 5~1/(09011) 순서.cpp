#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101];
int ans[101];
bool use[101];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		memset(use, 0, sizeof(use));
		memset(ans, -1, sizeof(ans));
		int N;
		cin >> N;
		FOR(i, 1, N)
			cin >> arr[i];
		ROF(i, N, 1) {
			int cnt = 0;
			FOR(j, 1, N) {
				if (use[j] == 0)
					cnt++;
				if (cnt == arr[i] + 1) {
					ans[i] = j;
					use[j] = 1;
					break;
				}
			}
		}
		bool flag = true;
		FOR(i, 1, N) {
			if (ans[i] == -1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			FOR(i, 1, N) {
				cout << ans[i] << " ";
			}
		}
		else {
			cout << "IMPOSSIBLE";
		}
		cout << "\n";
	}


	return 0;
}