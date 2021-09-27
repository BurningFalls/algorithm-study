#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) ll(s.size())

int N, C;
int arr[31];
vector<ll> v[2];

void DFS(int left, int right, ll sum, int idx) {
	if (sum > C)
		return;
	if (left == right) {
		if (sum != 0)
			v[idx].push_back(sum);
		return;
	}
	DFS(left + 1, right, sum, idx);
	DFS(left + 1, right, sum + arr[left], idx);
}

int main() {
	FASTIO;
	cin >> N >> C;
	FOR(i, 0, N - 1)
		cin >> arr[i];
	int mid = N / 2;
	DFS(0, mid, 0, 0);
	DFS(mid, N, 0, 1);

	ll ans = LEN(v[0]) + LEN(v[1]) + 1;
	sort(v[1].begin(), v[1].end());
	for (ll x : v[0]) {
		int ub = upper_bound(v[1].begin(), v[1].end(), C - x) - v[1].begin();
		ans += ub;
	}
	cout << ans;

	return 0;
}