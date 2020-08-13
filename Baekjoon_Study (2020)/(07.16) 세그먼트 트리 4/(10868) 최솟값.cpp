#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[100001];
int tree[400001];

int Init(int node, int start, int end) {
	if (start == end)
		return tree[node] = num[start];

	int mid = (start + end) / 2;
	int left_query, right_query;
	left_query = Init(node * 2, start, mid);
	right_query = Init(node * 2 + 1, mid + 1, end);
	return tree[node] = min(left_query, right_query);
}

int Query(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return 1000000001;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	int left_query, right_query;
	left_query = Query(node * 2, start, mid, left, right);
	right_query = Query(node * 2 + 1, mid + 1, end, left, right);
	return min(left_query, right_query);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int a, b;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	Init(1, 1, N);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << Query(1, 1, N, a, b) << "\n";
	}

	return 0;
}