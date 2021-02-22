#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int vis[100001] = { 0, };
int cnt = 0;
int ans = 0;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, 2 * N) {
		int num;
		cin >> num;
		if (vis[num] == 0) {
			vis[num] = 1;
			cnt++;
		}
		else if (vis[num] == 1) {
			cnt--;
		}
		ans = max(ans, cnt);
	}
	cout << ans;

	return 0;
}