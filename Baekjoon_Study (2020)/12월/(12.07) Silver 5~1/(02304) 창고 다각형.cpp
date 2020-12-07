#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pii arr[1001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i].first >> arr[i].second;
	sort(arr + 1, arr + N + 1);
	int ans = 0;
	int cur_x, cur_y;
	cur_x = arr[1].first;
	cur_y = arr[1].second;
	int left, right;
	FOR(i, 2, N) {
		if (cur_y < arr[i].second) {
			ans += (arr[i].first - cur_x) * cur_y;
			cur_x = arr[i].first;
			cur_y = arr[i].second;
		}
	}
	left = cur_x;
	FOR(i, 1, N)
		arr[i].first++;
	cur_x = arr[N].first;
	cur_y = arr[N].second;
	ROF(i, N - 1, 1) {
		if (cur_y < arr[i].second) {
			ans += (cur_x - arr[i].first) * cur_y;
			cur_x = arr[i].first;
			cur_y = arr[i].second;
		}
	}
	right = cur_x;
	ans += (right - left) * cur_y;
	cout << ans;

	return 0;
}