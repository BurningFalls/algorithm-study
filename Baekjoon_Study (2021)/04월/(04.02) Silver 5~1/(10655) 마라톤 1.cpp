#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pair<ll, ll> arr[100001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i].first >> arr[i].second;
	}
	ll maxi = 0;
	ll sum = 0;
	FOR(i, 2, N - 1) {
		ll x = abs(arr[i].first - arr[i - 1].first) + abs(arr[i].second - arr[i - 1].second);
		sum += x;
		ll y = abs(arr[i + 1].first - arr[i].first) + abs(arr[i + 1].second - arr[i].second);
		ll z = abs(arr[i + 1].first - arr[i - 1].first) + abs(arr[i + 1].second - arr[i - 1].second);
		maxi = max(maxi, x + y - z);
	}
	sum += abs(arr[N].first - arr[N - 1].first) + abs(arr[N].second - arr[N - 1].second);
	cout << sum - maxi;

	return 0;
}