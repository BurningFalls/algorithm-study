#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1000000

int N, M, K;
ll arr[MAX + 1];
ll tree[4 * MAX + 1];
ll lazy[4 * MAX + 1];

ll Init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	ll LQ = Init(node * 2, start, mid);
	ll RQ = Init(node * 2 + 1, mid + 1, end);
	return tree[node] = LQ + RQ;
}

void Update_Lazy(int node, int start, int end) {
	// lazy 값이 있으면
	if (lazy[node] != 0) {
		// lazy update
		tree[node] += ((ll)end - start + 1) * lazy[node];
		// leaf가 아니면
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

ll Sum(int node, int start, int end, int left, int right) {
	Update_Lazy(node, start, end);
	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	ll LQ = Sum(node * 2, start, mid, left, right);
	ll RQ = Sum(node * 2 + 1, mid + 1, end, left, right);
	return LQ + RQ;
}

void Update_Range(int node, int start, int end, int left, int right, ll diff) {
	Update_Lazy(node, start, end);
	if (end < left || right < start)
		return;
	if (left <= start && end <= right) {
		tree[node] += ((ll)end - start + 1) * diff;
		// 자식 노드가 있다면 자식 노드에게 lazy를 물려줌
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	Update_Range(node * 2, start, mid, left, right, diff);
	Update_Range(node * 2 + 1, mid + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	Init(1, 1, N);
	FOR(i, 1, M + K) {
		int a, b, c;
		ll d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			Update_Range(1, 1, N, b, c, d);
		}
		else if (a == 2) {
			cin >> b >> c;
			cout << Sum(1, 1, N, b, c) << "\n";
		}
	}

	return 0;
}