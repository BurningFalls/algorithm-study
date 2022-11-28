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

bool is_Prime(int x) {
	if (x <= 1) {
		return false;
	}
	int sqrtx = sqrt(x);
	FOR(i, 2, sqrtx) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> v(N + 1);
	vector<int> sum(N + 1, 0);
	FOR(i, 1, N) {
		cin >> v[i];
		if (i == 1) {
			sum[i] = v[i];
		}
		else {
			sum[i] = sum[i - 1] + v[i];
		}
	}
	int cnt = 0;
	FOR(i, 1, N) {
		FOR(j, i, N) {
			int tmp = sum[j] - sum[i - 1];
			int len = j - i + 1;
			cnt += (is_Prime(tmp) && is_Prime(len));
		}
	}
	cout << cnt;

	return 0;
}