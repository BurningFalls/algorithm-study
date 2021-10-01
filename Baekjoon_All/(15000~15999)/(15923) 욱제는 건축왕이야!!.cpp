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
	int N;
	int arr[21][2];
	cin >> N;
	FOR(i, 0, N - 1) {
		FOR(j, 0, 1) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	FOR(i, 0, N - 1) {
		ans += abs(arr[(i + 1) % N][0] - arr[i][0]) + abs(arr[(i + 1) % N][1] - arr[i][1]);
	}
	cout << ans;

	return 0;
}