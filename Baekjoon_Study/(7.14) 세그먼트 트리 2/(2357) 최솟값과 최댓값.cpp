#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001];
pair<int, int> tree[400001];

pair<int, int> Make_Tree(int node, int start, int end) {
	if (start == end)
		return tree[node] = make_pair(arr[start], arr[start]);

	int mid = (start + end) / 2;
	pair<int, int> LEFT, RIGHT;
	LEFT = Make_Tree(node * 2, start, mid);
	RIGHT = Make_Tree(node * 2 + 1, mid + 1, end);
	return tree[node] = make_pair(min(LEFT.first, RIGHT.first), max(LEFT.second, RIGHT.second));
}

pair<int, int> Find(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return make_pair(1000000001, 0);
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	pair<int, int> LEFT, RIGHT;
	LEFT = Find(node * 2, start, mid, left, right);
	RIGHT = Find(node * 2 + 1, mid + 1, end, left, right);
	return make_pair(min(LEFT.first, RIGHT.first), max(LEFT.second, RIGHT.second));
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int a, b;
	pair<int, int> ans;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	Make_Tree(1, 1, N);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		ans = Find(1, 1, N, a, b);
		cout << ans.first << " " << ans.second << "\n";
	}

	return 0;
}