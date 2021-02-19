#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int M, N, L;
int arr[100001];
int x[100001], y[100001];

int main() {
	FASTIO;
	cin >> M >> N >> L;
	FOR(i, 1, M) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + M + 1);
	FOR(i, 1, N)
		cin >> x[i] >> y[i];
	int ans = 0;
	FOR(i, 1, N) {
		if (L < y[i]) continue;
		int left = x[i] - (L - y[i]);
		int right = x[i] + (L - y[i]);
		if (arr[M] < left) continue;
		int lb = *lower_bound(arr + 1, arr + M + 1, left);
		if (lb <= right)
			ans++;
	}
	cout << ans;

	return 0;
}