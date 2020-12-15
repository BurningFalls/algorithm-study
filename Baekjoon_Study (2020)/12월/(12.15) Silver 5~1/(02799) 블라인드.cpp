#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int M, N;
char arr[503][503];
int ans[17] = { 0, };
int num[102] = { 0, };

int main() {
	FASTIO;
	cin >> M >> N;
	FOR(i, 1, 5 * M + 1) {
		FOR(j, 1, 5 * N + 1) {
			cin >> arr[i][j];
		}
	}
	int a, b, c;
	FOR(i, 1, 5 * M + 1) {
		if (i % 5 == 1) {
			if (i != 1) {
				FOR(j, 1, N) {
					ans[num[j]]++;
				}
			}
			FOR(j, 1, N)
				num[j] = 0;
		}
		else {
			FOR(j, 1, N) {
				if (arr[i][(j - 1) * 5 + 2] == '*') {
					num[j] += pow(2, ((i - 1) % 5 - 1));
				}
			}
		}
	}
	cout << ans[0] << " " << ans[1] << " " << ans[3] << " " << ans[7] << " " << ans[15];

	return 0;
}