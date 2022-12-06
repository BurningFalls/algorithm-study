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
	int N, M, J;
	cin >> N >> M;
	cin >> J;
	int ans = 0;
	int left = 1, right = left + M - 1;
	FOR(i, 1, J) {
		int num;
		cin >> num;
		if (right < num) {
			ans += num - right;
			right = num;
			left = right - M + 1;
		}
		else if (num < left) {
			ans += left - num;
			left = num;
			right = left + M - 1;
		}
	}
	cout << ans;

	return 0;
}