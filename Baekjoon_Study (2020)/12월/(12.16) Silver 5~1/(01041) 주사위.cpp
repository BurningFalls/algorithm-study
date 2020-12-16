#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(ll i=(a);i>=(b);i--)
#define pii pair<ll, ll>
#define INF 200

bool USE3[8][6] = { {1, 1, 1, 0, 0, 0},
{1, 1, 0, 1, 0, 0},
{1, 0, 0, 1, 1, 0},
{1, 0, 1, 0, 1, 0},
{0, 0, 1, 0, 1, 1},
{0, 1, 1, 0, 0, 1},
{0, 1, 0, 1, 0, 1},
{0, 0, 0, 1, 1, 1} };

int main() {
	FASTIO;
	ll N;
	ll arr[6];
	ll minimum = INF;
	cin >> N;
	FOR(i, 0, 5) {
		cin >> arr[i];
		minimum = min(minimum, arr[i]);
	}
	if (N == 1) {
		sort(arr, arr + 6);
		ll sum = 0;
		FOR(i, 0, 4)
			sum += arr[i];
		cout << sum;
		return 0;
	}
	ll min_sum3 = INF;
	FOR(i, 0, 7) {
		ll sum = 0;
		FOR(j, 0, 5) {
			if (USE3[i][j])
				sum += arr[j];
		}
		min_sum3 = min(min_sum3, sum);
	}
	ll min_sum2 = INF;
	FOR(i, 0, 5) {
		FOR(j, i + 1, 5) {
			if (i + j == 5) continue;
			min_sum2 = min(min_sum2, arr[i] + arr[j]);
		}
	}
	cout << 4 * min_sum3 + (8 * N - 12) * min_sum2 + (N - 2) * (5 * N - 6) * minimum;

	return 0;
}