#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

int N;
ll height[100001];
ll tree[400001];

void Init(int node, int start, int end) {
	if (start == end) {
		tree[node] = start;
		return;
	}

	int mid = (start + end) / 2;
	Init(node * 2, start, mid);
	Init(node * 2 + 1, mid + 1, end);
	if (height[tree[node * 2]] < height[tree[node * 2 + 1]])
		tree[node] = tree[node * 2];
	else if (height[tree[node * 2]] >= height[tree[node * 2 + 1]])
		tree[node] = tree[node * 2 + 1];
}

int Query(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return -1;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	int left_query, right_query;
	left_query = Query(node * 2, start, mid, left, right);
	right_query = Query(node * 2 + 1, mid + 1, end, left, right);
	if (left_query == -1)
		return right_query;
	else if (right_query == -1)
		return left_query;
	else if (height[left_query] < height[right_query])
		return left_query;
	else if (height[left_query] >= height[right_query])
		return right_query;
}

ll Get_MaxArea(int start, int end) {
	int idx = Query(1, 1, N, start, end);
	ll area = (end - start + 1) * height[idx];
	ll temp;

	if (start < idx) {
		temp = Get_MaxArea(start, idx - 1);
		area = max(area, temp);
	}
	if (idx < end) {
		temp = Get_MaxArea(idx + 1, end);
		area = max(area, temp);
	}
	return area;
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		for (int i = 1; i <= N; i++)
			cin >> height[i];
		Init(1, 1, N);
		cout << Get_MaxArea(1, N) << "\n";
	}

	return 0;
}