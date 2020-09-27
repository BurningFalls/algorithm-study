#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int cnt1[500001] = { 0, };
int cnt2[500001] = { 0, };

int main() {
	FASTIO;
	int N, H;
	int num;
	int ans = 200001;
	int cnt = 0;
	cin >> N >> H;
	FOR(i, 0, N - 1) {
		cin >> num;
		if (i % 2 == 0)
			cnt1[num]++;
		else
			cnt2[H + 1 - num]++;
	}
	ROF(i, H - 1, 1)
		cnt1[i] += cnt1[i + 1];
	FOR(i, 2, H)
		cnt2[i] += cnt2[i - 1];
	FOR(i, 1, H) {
		if (ans > cnt1[i] + cnt2[i]) {
			ans = cnt1[i] + cnt2[i];
			cnt = 1;
		}
		else if (ans == cnt1[i] + cnt2[i])
			cnt++;
	}
	cout << ans << " " << cnt;

	return 0;
}