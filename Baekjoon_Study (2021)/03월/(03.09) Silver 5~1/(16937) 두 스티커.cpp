#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int H, W, N;
pii arr[101];

bool Check(int a1, int a2, int b1, int b2, int c1, int c2) {
	if ((b1 + c1 <= a1) && b2 <= a2 && c2 <= a2)
		return true;
	if ((b2 + c2 <= a2) && b1 <= a1 && c1 <= a1)
		return true;
	return false;
}

int main() {
	FASTIO;
	cin >> H >> W;
	cin >> N;
	FOR(i, 1, N) {
		int R, C;
		cin >> R >> C;
		arr[i] = { R, C };
	}
	int ans = 0;
	FOR(a, 1, N) {
		FOR(b, a + 1, N) {
			bool flag = false;
			int max1 = max(arr[a].first, arr[a].second);
			int min1 = min(arr[a].first, arr[a].second);
			int max2 = max(arr[b].first, arr[b].second);
			int min2 = min(arr[b].first, arr[b].second);
			flag |= Check(max(H, W), min(H, W), max1, min1, max2, min2);
			flag |= Check(max(H, W), min(H, W), max1, min1, min2, max2);
			flag |= Check(max(H, W), min(H, W), min1, max1, max2, min2);
			flag |= Check(max(H, W), min(H, W), min1, max1, min2, max2);
			flag |= Check(min(H, W), max(H, W), max1, min1, max2, min2);
			flag |= Check(min(H, W), max(H, W), max1, min1, min2, max2);
			flag |= Check(min(H, W), max(H, W), min1, max1, max2, min2);
			flag |= Check(min(H, W), max(H, W), min1, max1, min2, max2);
			if (flag)
				ans = max(ans, max1 * min1 + max2 * min2);
		}
	}
	cout << ans;

	return 0;
}