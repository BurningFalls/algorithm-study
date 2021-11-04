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

struct NODE {
	int l, r;
	int idx;
};

bool compare(NODE a, NODE b) {
	return a.l < b.l;
}

NODE Log[100001];
int Log_idx[100001];

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	FOR(i, 1, N) {
		int num;
		cin >> Log[i].l >> Log[i].r >> num;
		Log[i].idx = i;
	}
	sort(Log + 1, Log + N + 1, compare);
	int log_idx = 0;
	int left = -1, right = -1;
	FOR(i, 1, N) {
		if (left <= Log[i].l && Log[i].l <= right) {
			right = max(right, Log[i].r);
			Log_idx[Log[i].idx] = log_idx;
		}
		else {
			left = Log[i].l;
			right = Log[i].r;
			Log_idx[Log[i].idx] = ++log_idx;
		}
	}
	FOR(q, 1, Q) {
		int a, b;
		cin >> a >> b;
		cout << (Log_idx[a] == Log_idx[b]) << "\n";
	}


	return 0;
}