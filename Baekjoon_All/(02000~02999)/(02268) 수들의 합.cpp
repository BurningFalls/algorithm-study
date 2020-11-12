#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1000000

int N;
ll tree[4 * MAX + 1] = { 0, };

ll Sum(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	ll LQ = Sum(node * 2, start, mid, left, right);
	ll RQ = Sum(node * 2 + 1, mid + 1, end, left, right);
	return LQ + RQ;
}

ll Update(int node, int start, int end, int index, ll ch) {
	if (index < start || end < index)
		return tree[node];
	if (start == end)
		return tree[node] = ch;
	int mid = (start + end) / 2;
	ll LQ = Update(node * 2, start, mid, index, ch);
	ll RQ = Update(node * 2 + 1, mid + 1, end, index, ch);
	return tree[node] = LQ + RQ;
}

int main() {
	FASTIO;
	int M;
	cin >> N >> M;
	FOR(i, 1, M) {
		int order;
		cin >> order;
		if (order == 0) {
			int a, b;
			cin >> a >> b;
			cout << Sum(1, 1, N, min(a, b), max(a, b)) << "\n";
		}
		else if (order == 1) {
			int a, c;
			cin >> a >> c;
			Update(1, 1, N, a, c);
		}
	}

	return 0;
}