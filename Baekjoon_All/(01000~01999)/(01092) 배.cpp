#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
int limit[51];
int M;
int weight[10001];
int possible[51] = { 0, };

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> limit[i];
	cin >> M;
	FOR(i, 1, M)
		cin >> weight[i];
	sort(limit + 1, limit + N + 1);
	sort(weight + 1, weight + M + 1);
	if (limit[N] < weight[M]) {
		cout << -1;
		return 0;
	}
	int l_idx = 1;
	int w_idx = 1;
	while (l_idx <= N && w_idx <= M) {
		if (limit[l_idx] >= weight[w_idx]) {
			possible[l_idx]++;
			w_idx++;
		}
		else
			l_idx++;
	}
	int cnt = 0;
	int ans = 0;
	while (true) {
		ROF(i, N, 1) {
			ROF(j, i, 1) {
				if (possible[j]) {
					possible[j]--;
					cnt++;
					break;
				}
			}
			if (cnt == M)
				break;
		}
		ans++;
		if (cnt == M)
			break;
	}
	cout << ans;

	return 0;
}