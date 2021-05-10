#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int cnt[10];

bool Seperate(int n) {
	FOR(i, 0, 9)
		cnt[i] = 0;
	int num[4] = { 2, 3, 5, 7 };
	FOR(i, 0, 3) {
		while (n % num[i] == 0 && n != 1) {
			n /= num[i];
			cnt[num[i]]++;
		}
	}
	return (n == 1);
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N == 1) {
			cout << 1 << "\n";
			continue;
		}
		bool flag = Seperate(N);
		if (!flag)
			cout << -1 << "\n";
		else {
			cnt[9] += cnt[3] / 2;
			cnt[3] = cnt[3] % 2;
			cnt[8] = cnt[2] / 3;
			cnt[2] = cnt[2] % 3;
			int tmp = min(cnt[2], cnt[3]);
			cnt[6] += tmp;
			cnt[3] -= tmp;
			cnt[2] -= tmp;
			cnt[4] += cnt[2] / 2;
			cnt[2] = cnt[2] % 2;
			int ans = 0;
			FOR(i, 0, 9)
				ans += cnt[i];
			cout << ans << "\n";
		}
	}


	return 0;
}