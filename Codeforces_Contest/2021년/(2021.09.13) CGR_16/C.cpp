#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

char arr[2][100001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 0, 1) {
			FOR(j, 1, N) {
				cin >> arr[i][j];
			}
		}
		int idx = 1;
		int ans = 0;
		while (idx <= N) {
			int tmp = (arr[0][idx] - '0') + (arr[1][idx] - '0');
			if (tmp == 1) {
				ans += 2;
			}
			else if (tmp == 0) {
				if (idx == N)
					ans += 1;
				else {
					int tmp2 = (arr[0][idx + 1] - '0') + (arr[1][idx + 1] - '0');
					if (tmp2 == 2) {
						ans += 2;
						idx++;
					}
					else
						ans += 1;
				}
			}
			else if (tmp == 2) {
				if (idx == N)
					ans += 0;
				else {
					int tmp2 = (arr[0][idx + 1] - '0') + (arr[1][idx + 1] - '0');
					if (tmp2 == 0) {
						ans += 2;
						idx++;
					}
					else
						ans += 0;
				}
			}
			idx++;
		}
		cout << ans << "\n";
	}

	return 0;
}