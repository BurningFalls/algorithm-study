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
	int M;
	cin >> M;
	vector<int> P(M);
	vector<int> v;
	set<int> s;
	FOR(i, 0, M - 1) {
		cin >> P[i];
		s.insert(P[i]);
	}
	if (LEN(s) == 1) {
		cout << 1;
		return 0;
	}
	FOR(i, 1, M - 1) {
		if (P[i - 1] > P[i]) {
			v.push_back(-1);
		}
		else if (P[i - 1] < P[i]) {
			v.push_back(1);
		}
	}

	int max_cnt = 0;
	int cnt = 1;
	FOR(i, 1, LEN(v) - 1) {
		if (v[i - 1] == v[i]) {
			cnt++;
		}
		else if (v[i - 1] != v[i]) {
			max_cnt = max(max_cnt, cnt);
			cnt = 1;
		}
	}
	max_cnt = max(max_cnt, cnt);
	cout << max_cnt + 1;

	return 0;
}