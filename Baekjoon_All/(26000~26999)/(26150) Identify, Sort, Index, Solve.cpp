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

struct NODE {
	string name;
	int idx;
	int diff;

	bool operator<(const NODE n) const {
		return idx < n.idx;
	}
};

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<NODE> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i].name >> v[i].idx >> v[i].diff;
	}
	sort(ALL(v));
	FOR(i, 0, N - 1) {
		char x = v[i].name[v[i].diff - 1];
		if (x >= 'a' && x <= 'z') {
			x = x - 'a' + 'A';
		}
		cout << x;
	}

	return 0;
}