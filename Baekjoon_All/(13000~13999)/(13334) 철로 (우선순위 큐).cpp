#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<ll, ll>

int N, D;
pii arr[100001];
priority_queue<ll> pq;

bool cmp(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		arr[i] = { min(a, b), max(a, b) };
	}
	cin >> D;
	sort(arr + 1, arr + N + 1, cmp);
	ll left = 0, right = 0;
	int len = 0;
	int ans = 0;
	FOR(i, 1, N) {
		ll dist = arr[i].second - arr[i].first;
		if (dist > D) continue;
		right = arr[i].second;
		left = right - D;
		while (!pq.empty() && -pq.top() < left) {
			pq.pop();
			len--;
		}
		pq.push(-arr[i].first);
		len++;
		ans = max(ans, len);
	}
	cout << ans;

	return 0;
}