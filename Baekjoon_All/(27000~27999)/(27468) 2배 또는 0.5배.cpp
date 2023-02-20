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
	cout << "YES\n";
	vector<int> d;
	if (N % 4 == 1) {
		d = { 0, 1, 2, -1 };
	}
	else {
		d = { 0, -1, 2, 1 };
	}
	int idx = (N % 4 == 1 ? 1 : 2);
	int cnt = 0;
	while (cnt < N) {
		int num = idx;
		FOR(i, 0, 3) {
			num += d[i];
			cout << num << " ";
			cnt++;
			if (cnt == N) break;
		}
		idx += 4;
	}

	return 0;
}