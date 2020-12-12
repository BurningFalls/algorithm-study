#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool arr[102][102] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(t, 1, N) {
		int a, b;
		cin >> a >> b;
		FOR(i, a, a + 9) {
			FOR(j, b, b + 9) {
				arr[i][j] = 1;
			}
		}
	}
	int ans = 0;
	FOR(i, 0, 101) {
		FOR(j, 0, 100) {
			if ((arr[i][j] ^ arr[i][j + 1]) == 1)
				ans++;
		}
		FOR(j, 0, 100) {
			if ((arr[j][i] ^ arr[j + 1][i]) == 1)
				ans++;
		}
	}
	cout << ans;

	return 0;
}