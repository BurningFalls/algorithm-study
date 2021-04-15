#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 1000000000003

int N, M;
ll A[1000001];

int main() {
	FASTIO;
	ll mini = 1000001;
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> A[i];
		mini = min(mini, A[i]);
	}
	ll left = 1, right = mini * M;
	ll ans = INF;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		FOR(i, 1, N)
			sum += mid / A[i];
		if (sum >= M) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans;

	return 0;
}