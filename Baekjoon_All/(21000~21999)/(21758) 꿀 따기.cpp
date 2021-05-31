#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];
int sum[100001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	sum[0] = 0;
	FOR(i, 1, N) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	int ans = 0;
	int tmp;
	FOR(i, 2, N - 1) {
		tmp = (sum[i] - sum[1]) + (sum[N - 1] - sum[i - 1]);
		ans = max(ans, tmp);
		tmp = (sum[N - 1] - arr[i]) + (sum[i - 1]);
		ans = max(ans, tmp);
		tmp = (sum[N] - sum[1] - arr[i]) + (sum[N] - sum[i]);
		ans = max(ans, tmp);
	}
	cout << ans;


	return 0;
}