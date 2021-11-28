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
	int s;
	int e;
	int c;
};

bool compare(NODE a, NODE b) {
	return a.s < b.s;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<NODE> v(N);
	vector<NODE> ans;
	FOR(i, 0, N - 1) {
		int S, E, C;
		cin >> S >> E >> C;
		v[i] = { S, E, C };
	}
	sort(ALL(v), compare);
	int left = v[0].s;
	int right = v[0].e;
	int cost = v[0].c;
	FOR(i, 1, N - 1) {
		if (right < v[i].s) {
			ans.push_back({ left, right, cost });
			left = v[i].s;
			right = v[i].e;
			cost = v[i].c;
		}
		else if (v[i].s <= right) {
			right = max(right, v[i].e);
			cost = min(cost, v[i].c);
		}
	}
	ans.push_back({ left, right, cost });
	cout << LEN(ans) << "\n";
	for (NODE n : ans) {
		cout << n.s << " " << n.e << " " << n.c << "\n";
	}

	return 0;
}