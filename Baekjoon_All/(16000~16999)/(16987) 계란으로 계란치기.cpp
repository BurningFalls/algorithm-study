#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
pii arr[8];
bool crashed[8] = { 0, };
int ans = 0;

void DFS(int cnt) {
	if (cnt == N) {
		int egg = 0;
		FOR(i, 0, N - 1) {
			if (crashed[i])
				egg++;
		}
		ans = max(ans, egg);
		return;
	}
	if (crashed[cnt])
		DFS(cnt + 1);
	else {
		bool ch_cnt = false;
		bool ch_i = false;
		bool do_flag = false;
		FOR(i, 0, N - 1) {
			if (cnt == i) continue;
			if (crashed[i]) continue;
			do_flag = true;
			arr[cnt].first -= arr[i].second;
			if (arr[cnt].first <= 0) {
				crashed[cnt] = 1;
				ch_cnt = true;
			}
			arr[i].first -= arr[cnt].second;
			if (arr[i].first <= 0) {
				crashed[i] = 1;
				ch_i = true;
			}
			DFS(cnt + 1);
			arr[cnt].first += arr[i].second;
			if (ch_cnt)
				crashed[cnt] = 0;
			arr[i].first += arr[cnt].second;
			if (ch_i)
				crashed[i] = 0;
		}
		if (!do_flag)
			DFS(cnt + 1);
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1)
		cin >> arr[i].first >> arr[i].second;
	DFS(0);
	cout << ans;

	return 0;
}