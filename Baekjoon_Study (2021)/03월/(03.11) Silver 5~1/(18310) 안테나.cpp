#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
ll arr[200001];
ll sum[200001];

int main() {
	FASTIO;
	cin >> N;
	sum[0] = 0;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	FOR(i, 1, N)
		sum[i] = sum[i - 1] + arr[i];
	int pos = arr[1];
	ll minimum = sum[N] - arr[1] * N;
	int ans = 1;
	FOR(i, 2, N) {
		ll tmp1 = sum[N] - sum[i - 1] - arr[i] * ((ll)N + 1 - i);
		ll tmp2 = arr[i] * i - sum[i];
		if (minimum > tmp1 + tmp2) {
			minimum = tmp1 + tmp2;
			ans = arr[i];
		}
	}
	cout << ans;

	return 0;
}