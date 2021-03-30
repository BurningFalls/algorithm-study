#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[500001];
ll sum[500001];

int main() {
	FASTIO;
	cin >> N;
	sum[0] = 0;
	FOR(i, 1, N) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	ll ans = 0;
	FOR(i, 1, N) {
		ans += arr[i] * (sum[N] - sum[i]);
	}
	cout << ans;


	return 0;
}