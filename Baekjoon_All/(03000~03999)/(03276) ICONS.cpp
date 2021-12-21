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
	int sqrtn = sqrt(N);
	int min_sum = INF;
	pii ans = { 0, 0 };
	FOR(i, 1, N) {
		int a = i;
		int b = N / i;
		if (a * b != N) {
			b += 1;
		}
		if (min_sum > a + b) {
			min_sum = a + b;
			ans = { a, b };
		}
	}
	cout << ans.first << " " << ans.second;

	return 0;
}