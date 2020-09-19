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
	FOR(i, 1, n)
		cin >> arr[i];
	sort(arr + 1, arr + n + 1, greater<int>());
	cout << (n - 1) / 2 << "\n";
	int idx = 1;
	for (int i = 1; i <= n; i += 2) {
		ans[i] = arr[idx];
		idx++;
	}
	for (int i = 2; i <= n; i += 2) {
		ans[i] = arr[idx];
		idx++;
	}
	FOR(i, 1, n)
		cout << ans[i] << " ";

	return 0;
}