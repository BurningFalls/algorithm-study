#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int arr[100001];

int func(int mid) {
	int num = 1;
	int sum = mid;
	FOR(i, 1, N) {
		if (sum - arr[i] < 0) {
			sum = mid;
			num++;
		}
		sum -= arr[i];
	}
	return num;
}

int main() {
	FASTIO;
	int sum = 0;
	int maximum = 0;
	int ans = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> arr[i];
		maximum = max(maximum, arr[i]);
		sum += arr[i];
	}
	int left = maximum, right = sum;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (M >= func(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans;

	return 0;
}