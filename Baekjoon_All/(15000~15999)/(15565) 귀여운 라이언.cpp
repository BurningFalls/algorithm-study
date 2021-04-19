#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1000001];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	int sum = 0;
	int left = 0, right = 0;
	FOR(i, 1, N) {
		if (arr[i] == 1) {
			if (left == 0)
				left = i;
			sum++;
		}
		if (sum == K) {
			right = i;
			break;
		}
	}
	if (left == 0 || right == 0) {
		cout << -1;
		return 0;
	}
	int ans = right - left + 1;
	while (true) {
		right++;
		while (right <= N && arr[right] != 1)
			right++;
		if (right > N)
			break;
		left++;
		while (left <= right && arr[left] != 1)
			left++;
		if (left > right)
			break;
		ans = min(ans, right - left + 1);
	}
	cout << ans;

	return 0;
}