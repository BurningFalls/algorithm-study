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
	int N, M;
	cin >> N >> M;
	vector<int> v(N + 2, 1);
	v[0] = 0;
	v[N + 1] = 0;
	FOR(i, 0, M - 1) {
		int num;
		cin >> num;
		v[num] = 0;
	}

	FOR(i, 2, N - 1) {
		if (v[i] == 1) continue;
		if (v[i - 2] && v[i + 1]) v[i] = 1;
		if (v[i - 1] && v[i + 2]) v[i] = 1;
		if (v[i - 1] && v[i + 1]) v[i] = 1;
	}

	int sum = 0;
	int cnt = 0;
	FOR(i, 1, N + 1) {
		if (v[i] == 1) {
			cnt++;
		}
		else if (cnt != 0 && v[i] == 0) {
			sum += 5 + 2 * cnt;
			cnt = 0;
		}
	}
	cout << sum;

	return 0;
}