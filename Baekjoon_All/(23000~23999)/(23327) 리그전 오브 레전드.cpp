#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int N, Q;
ll arr[100001];
pll Tree[400001];

pll Init(int node, int start, int end) {
	if (start == end) {
		return Tree[node] = { arr[start], 0 };
	}
	int mid = (start + end) / 2;
	pll LQ = Init(node * 2, start, mid);
	pll RQ = Init(node * 2 + 1, mid + 1, end);
	ll L = LQ.first + RQ.first;
	ll R = LQ.second + RQ.second + LQ.first * RQ.first;
	return Tree[node] = { L, R };
}

pll Find(int node, int start, int end, int left, int right) {
	if (right < start || end < left) {
		return { 0, 0 };
	}
	if (left <= start && end <= right) {
		return Tree[node];
	}
	int mid = (start + end) / 2;
	pll LQ = Find(node * 2, start, mid, left, right);
	pll RQ = Find(node * 2 + 1, mid + 1, end, left, right);
	ll L = LQ.first + RQ.first;
	ll R = LQ.second + RQ.second + LQ.first * RQ.first;
	return { L, R };
}

int main() {
	FASTIO;
	cin >> N >> Q;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	Init(1, 1, N);
	FOR(q, 1, Q) {
		int l, r;
		cin >> l >> r;
		cout << Find(1, 1, N, l, r).second << "\n";
	}


	return 0;
}