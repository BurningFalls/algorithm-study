#include <bits/stdc++.h>
using namespace std;

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
	int N;
	cin >> N;
	vector<int> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	int left = v[0], right = v[1];
	FOR(i, 2, N - 1) {
		if (left > right) {
			right += v[i];
		}
		else {
			left += v[i];
		}
	}
	int diff = abs(left - right);
	vector<int> tmp = { 100, 50, 20, 10, 5, 2, 1 };

	int cnt = 0;
	FOR(i, 0, 6) {
		cnt += diff / tmp[i];
		diff %= tmp[i];
	}
	cout << cnt;

	return 0;
}