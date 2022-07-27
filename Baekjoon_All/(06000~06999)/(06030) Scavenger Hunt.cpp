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
	int P, Q;
	cin >> P >> Q;
	vector<int> p, q;
	int sp = sqrt(P), sq = sqrt(Q);
	FOR(i, 1, sp) {
		if (P % i == 0) {
			p.push_back(i);
			p.push_back(P / i);
		}
	}
	if (sp * sp == P) {
		p.pop_back();
	}
	FOR(i, 1, sq) {
		if (Q % i == 0) {
			q.push_back(i);
			q.push_back(Q / i);
		}
	}
	if (sq * sq == Q) {
		q.pop_back();
	}
	sort(ALL(p));
	sort(ALL(q));
	FOR(i, 0, LEN(p) - 1) {
		FOR(j, 0, LEN(q) - 1) {
			cout << p[i] << " " << q[j] << "\n";
		}
	}

	return 0;
}