#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, M;
int cnt[300001];

int main() {
	FASTIO;
	int maximum = 0;
	cin >> N >> M;
	FOR(i, 1, M) {
		cin >> cnt[i];
		maximum = max(maximum, cnt[i]);
	}
	int left = 1, right = maximum;
	int ans = maximum;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		FOR(i, 1, M) {
			if (cnt[i] % mid == 0)
				sum += cnt[i] / mid;
			else
				sum += cnt[i] / mid + 1;
		}
		if (sum > N) {
			left = mid + 1;
		}
		else if (sum <= N) {
			right = mid - 1;
			ans = min(ans, mid);
		}
	}
	cout << ans;

	return 0;
}