#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	int N;
	pii arr[101];
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
	}
	sort(arr + 1, arr + N + 1);
	int ans = arr[1].first + arr[1].second;
	FOR(i, 2, N) {
		ans = max(ans, arr[i].first) + arr[i].second;
	}
	cout << ans;

	return 0;
}