#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll T[100001];
ll ans = -1;

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> T[i];
	sort(T + 1, T + N + 1);
	ll left = 0;
	ll right = M * T[N];
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		FOR(i, 1, N)
			sum += mid / T[i];
		if (sum >= M) {
			if (ans == -1)
				ans = mid;
			else
				ans = min(ans, mid);
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans;

	return 0;
}