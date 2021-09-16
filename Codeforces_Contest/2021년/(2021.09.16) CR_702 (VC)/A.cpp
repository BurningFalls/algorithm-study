#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int arr[51];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N)
			cin >> arr[i];
		int ans = 0;
		FOR(i, 1, N - 1) {
			int a = min(arr[i], arr[i + 1]);
			int b = max(arr[i], arr[i + 1]);
			while (a * 2 < b) {
				a *= 2;
				ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}