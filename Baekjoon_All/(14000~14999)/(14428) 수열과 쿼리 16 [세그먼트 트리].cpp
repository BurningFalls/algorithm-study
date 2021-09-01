#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000

int N;
int arr[100001];
pii tree[400001];

pii Init(int node, int start, int end) {
	if (start == end)
		return tree[node] = { arr[start], start };
	int mid = (start + end) / 2;
	pii LQ = Init(node * 2, start, mid);
	pii RQ = Init(node * 2 + 1, mid + 1, end);
	if (LQ.first == RQ.first)
		return tree[node] = { LQ.first, min(LQ.second, RQ.second) };
	return tree[node] = ((LQ.first < RQ.first) ? LQ : RQ);
}

pii Update(int node, int start, int end, int idx, int val) {
	if (idx < start || end < idx)
		return tree[node];
	if (start == end) {
		tree[node].first = val;
		return tree[node];
	}
	int mid = (start + end) / 2;
	pii LQ = Update(node * 2, start, mid, idx, val);
	pii RQ = Update(node * 2 + 1, mid + 1, end, idx, val);
	if (LQ.first == RQ.first)
		return tree[node] = { LQ.first, min(LQ.second, RQ.second) };
	return tree[node] = ((LQ.first < RQ.first) ? LQ : RQ);
}

pii Find(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return { INF, -1 };
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	pii LQ = Find(node * 2, start, mid, left, right);
	pii RQ = Find(node * 2 + 1, mid + 1, end, left, right);
	if (LQ.first == RQ.first)
		return { LQ.first, min(LQ.second, RQ.second) };
	return ((LQ.first < RQ.first) ? LQ : RQ);
}

int main() {
	FASTIO;
	int M;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	Init(1, 1, N);
	cin >> M;
	FOR(m, 1, M) {
		int kind, i, j;
		cin >> kind >> i >> j;
		if (kind == 1)
			Update(1, 1, N, i, j);
		else if (kind == 2)
			cout << Find(1, 1, N, i, j).second << "\n";
	}


	return 0;
}