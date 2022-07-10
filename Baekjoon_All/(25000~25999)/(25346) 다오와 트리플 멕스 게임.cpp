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
	set<int> s;
	int zero_cnt = 0;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		zero_cnt += (num == 0);
		s.insert(num);
	}
	if (zero_cnt == 0) {
		cout << 0;
	}
	else if (zero_cnt == N) {
		cout << 1;
	}
	else {
		int idx = 0;
		for (int x : s) {
			if (x != idx) break;
			idx++;
		}
		cout << idx + 2;
	}

	return 0;
}