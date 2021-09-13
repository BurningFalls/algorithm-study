#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())
#define MOD 1000000007

int arr[300001];
int ch[300001] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	FOR(i, 0, 29) {
		int cnt = 0;
		FOR(j, 1, N) {
			if (arr[j] & (1 << i))
				cnt++;
		}
		FOR(j, 1, cnt) {
			ch[j] |= (1 << i);
		}
	}
	ll ans = 1;
	FOR(i, 1, N)
		ans = (ans * ch[i]) % MOD;
	cout << ans;

	return 0;
}