#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int cnt[1001] = { 0, };

int main() {
	int N, M, L;
	cin >> N >> M >> L;
	int pos = 1;
	int ans = 0;
	while (true) {
		ans++;
		cnt[pos]++;
		if (cnt[pos] == M)
			break;
		if (cnt[pos] % 2 == 1) {
			pos = (pos + L) % N;
		}
		else if (cnt[pos] % 2 == 0) {
			pos = (pos + N - L) % N;
		}
	}
	cout << ans - 1;

	return 0;
}