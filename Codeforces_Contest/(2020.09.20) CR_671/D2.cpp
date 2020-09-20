#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[100001];
int ans[100001];

int main() {
	FASTIO;
	int n;
	cin >> n;
	FOR(i, 0, n - 1) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int idx = n / 2;
	for (int i = 0; i < n; i += 2) {
		ans[i] = arr[idx];
		idx++;
	}
	idx = 0;
	for (int i = 1; i < n; i += 2) {
		ans[i] = arr[idx];
		idx++;
	}
	int cnt = 0;
	FOR(i, 1, n - 2) {
		if (ans[i - 1] > ans[i] && ans[i] < ans[i + 1])
			cnt++;
	}
	cout << cnt << "\n";
	FOR(i, 0, n - 1)
		cout << ans[i] << " ";

	return 0;
}