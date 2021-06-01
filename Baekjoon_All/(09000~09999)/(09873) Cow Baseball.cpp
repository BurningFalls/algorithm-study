#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	int cnt = 0;
	FOR(i, 1, N - 2) {
		FOR(j, i + 1, N - 1) {
			int left = arr[j] + (arr[j] - arr[i]);
			int right = arr[j] + 2 * (arr[j] - arr[i]);
			int lb = lower_bound(arr + (j + 1), arr + N + 1, left) - arr;
			int ub = upper_bound(arr + (j + 1), arr + N + 1, right) - arr;
			cnt += (ub - lb);
		}
	}
	cout << cnt;

	return 0;
}