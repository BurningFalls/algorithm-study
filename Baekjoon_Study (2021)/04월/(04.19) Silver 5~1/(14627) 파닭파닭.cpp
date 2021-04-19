#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int L[1000001];

int main() {
	FASTIO;
	int S, C;
	ll SUM = 0;
	cin >> S >> C;
	FOR(i, 1, S) {
		cin >> L[i];
		SUM += L[i];
	}
	ll left = 1, right = 1000000000;
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		FOR(i, 1, S) {
			sum += L[i] / mid;
		}
		if (sum >= C) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	ll ANS = SUM - C * ans;
	cout << ANS;

	return 0;
}