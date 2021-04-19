#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
double arr[100001];

int BS(double Size, int idx) {
	int left = 1;
	int right = idx - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] < Size * 0.9)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return idx - left;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	ll ans = 0;
	FOR(i, 2, N) {
		ans += BS(arr[i], i);
	}
	cout << ans;

	return 0;
}