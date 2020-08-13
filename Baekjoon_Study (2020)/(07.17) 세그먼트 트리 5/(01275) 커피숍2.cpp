#include <iostream>
using namespace std;

typedef long long int ll;

int N, Q;
ll num[100001];
ll tree[400001];

ll Init(int node, int start, int end) {
	if (start == end)
		return tree[node] = num[start];
	int mid = (start + end) / 2;
	ll left, right;
	left = Init(node * 2, start, mid);
	right = Init(node * 2 + 1, mid + 1, end);
	return tree[node] = left + right;
}

ll Sum(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	ll left_query, right_query;
	left_query = Sum(node * 2, start, mid, left, right);
	right_query = Sum(node * 2 + 1, mid + 1, end, left, right);
	return left_query + right_query;
}

void Update(int node, int start, int end, int idx, ll dif) {
	if (idx < start || end < idx)
		return;
	tree[node] += dif;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	Update(node * 2, start, mid, idx, dif);
	Update(node * 2 + 1, mid + 1, end, idx, dif);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll x, y, a, b;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	Init(1, 1, N);
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;
		if (x <= y)
			cout << Sum(1, 1, N, x, y) << "\n";
		else
			cout << Sum(1, 1, N, y, x) << "\n";
		Update(1, 1, N, a, b - num[a]);
		num[a] = b;
	}

	return 0;
}