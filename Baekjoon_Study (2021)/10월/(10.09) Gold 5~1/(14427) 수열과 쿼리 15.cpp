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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int N, M;
vector<int> A(100001);
vector<pii> Tree(400001);

pii Init(int node, int start, int end) {
	if (start == end)
		return Tree[node] = { A[start], start };
	int mid = (start + end) / 2;
	pii LQ = Init(node * 2, start, mid);
	pii RQ = Init(node * 2 + 1, mid + 1, end);
	if (LQ.first == RQ.first)
		return Tree[node] = { LQ.first, min(LQ.second, RQ.second) };
	else if (LQ.first > RQ.first)
		return Tree[node] = RQ;
	else if (LQ.first < RQ.first)
		return Tree[node] = LQ;
}

pii Update(int node, int start, int end, int idx, int val) {
	if (idx < start || end < idx)
		return Tree[node];
	if (start == end)
		return Tree[node] = { val, Tree[node].second };
	int mid = (start + end) / 2;
	pii LQ = Update(node * 2, start, mid, idx, val);
	pii RQ = Update(node * 2 + 1, mid + 1, end, idx, val);
	if (LQ.first == RQ.first)
		return Tree[node] = { LQ.first, min(LQ.second, RQ.second) };
	else if (LQ.first > RQ.first)
		return Tree[node] = RQ;
	else if (LQ.first < RQ.first)
		return Tree[node] = LQ;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	Init(1, 1, N);
	cin >> M;
	FOR(i, 1, M) {
		int kind;
		cin >> kind;
		if (kind == 1) {
			int idx, val;
			cin >> idx >> val;
			Update(1, 1, N, idx, val);
		}
		else if (kind == 2) {
			P1(Tree[1].second);
		}
	}

	return 0;
}