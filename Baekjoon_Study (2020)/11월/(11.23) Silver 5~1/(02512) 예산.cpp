#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[10001];

int main() {
	FASTIO;
	int N, M;
	int maximum = 0;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
		maximum = max(maximum, arr[i]);
	}
	cin >> M;
	int ans = M / N;
	int temp = 0;
	int left = ans, right = maximum;
	while (left <= right) {
		int mid = (left + right) / 2;
		temp = 0;
		FOR(i, 1, N) {
			temp += min(mid, arr[i]);
		}
		if (temp < M) {
			left = mid + 1;
			ans = mid;
		}
		else if (temp == M) {
			ans = mid;
			break;
		}
		else if (temp > M)
			right = mid - 1;
	}
	cout << ans;

	return 0;
}