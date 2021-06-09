#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[50001];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	int left = 0, right = 1000000000;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int idx = 1;
		FOR(i, 1, N) {
			if (arr[i] - arr[idx] > 2 * mid) {
				cnt++;
				idx = i;
			}
		}
		if (cnt <= K) {
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans;


	return 0;
}