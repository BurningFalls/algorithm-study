#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<ll> v(N);
	ll left_sum = 0;
	ll right_sum = 0;
	FOR(i, 0, N - 1) {
		cin >> v[i];
		right_sum += v[i];
	}
	sort(ALL(v), greater<int>());
	ll maxi = right_sum;
	FOR(i, 0, N - 1) {
		left_sum += v[i];
		right_sum -= v[i];
		maxi = max(maxi, left_sum * (i + 1) + right_sum);
	}
	cout << maxi;

	return 0;
}