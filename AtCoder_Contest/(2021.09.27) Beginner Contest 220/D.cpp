#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())
#define MOD 998244353

ll cnt[10] = { 0, };
ll arr[100001];
ll tmp[10];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	cnt[(arr[1] + arr[2]) % 10]++;
	cnt[(arr[1] * arr[2]) % 10]++;
	FOR(i, 3, N) {
		MEMSET(tmp, 0);
		FOR(j, 0, 9) {
			if (cnt[j] == 0) continue;
			tmp[(arr[i] + j) % 10] = (tmp[(arr[i] + j) % 10] + cnt[j]) % MOD;
			tmp[(arr[i] * j) % 10] = (tmp[(arr[i] * j) % 10] + cnt[j]) % MOD;
		}
		FOR(j, 0, 9)
			cnt[j] = tmp[j];
	}
	FOR(i, 0, 9)
		cout << cnt[i] << "\n";


	return 0;
}