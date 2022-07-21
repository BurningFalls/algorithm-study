#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	ll ans1 = 0, ans2 = 0;
	int zero_cnt = 0, one_cnt = 0;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		if (num % 2 == 0) {
			ans1 += (i - zero_cnt);
			zero_cnt++;
		}
		else if (num % 2 == 1) {
			ans2 += (i - one_cnt);
			one_cnt++;
		}
	}
	cout << min(ans1, ans2);

	return 0;
}