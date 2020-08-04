#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define mod 1000000007

int N, M, K;
ll num[1000001];
ll tree[4000001];

ll Init(int node, int start, int end) {
	if (start == end)
		return tree[node] = num[start];
	int mid = (start + end) / 2;
	ll left, right;
	left = Init(node * 2, start, mid);
	right = Init(node * 2 + 1, mid + 1, end);
	return tree[node] = (left * right) % mod;
}

ll Update(int node, int start, int end, int index, int val) {
	if (index < start || end < index)
		return tree[node];
	if (start == end)
		return tree[node] = val;
	int mid = (start + end) / 2;
	ll left, right;
	left = Update(node * 2, start, mid, index, val);
	right = Update(node * 2 + 1, mid + 1, end, index, val);
	return tree[node] = (left * right) % mod;
}

ll Query(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	ll left_query, right_query;
	left_query = Query(node * 2, start, mid, left, right);
	right_query = Query(node * 2 + 1, mid + 1, end, left, right);
	return (left_query * right_query) % mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int a, b, c;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	Init(1, 1, N);
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			Update(1, 1, N, b, c);
		}
		else if (a == 2) {
			cout << Query(1, 1, N, b, c) << "\n";
		}
	}

	return 0;
}