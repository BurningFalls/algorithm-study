#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000 + 1
#define INF 987654321

pair<int, int> tree[MAX];
int node_cnt[MAX] = { 0, };
int low[MAX];
int high[MAX] = { 0, };
int cur_col = 1;
int max_level = 1;

void DFS(int node, int cnt) {
	max_level = max(max_level, cnt);
	if (tree[node].first != -1)
		DFS(tree[node].first, cnt + 1);

	low[cnt] = min(low[cnt], cur_col);
	high[cnt] = max(high[cnt], cur_col);
	cur_col++;

	if (tree[node].second != -1)
		DFS(tree[node].second, cnt + 1);
}

int main() {
	int N;
	int cur_node;
	int left_node;
	int right_node;
	int root = 1;

	int width;
	int max_width = 0;
	int max_width_level = 1;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cur_node >> left_node >> right_node;
		node_cnt[cur_node]++;
		if (left_node != -1)
			node_cnt[left_node]++;
		if (right_node != -1)
			node_cnt[right_node]++;
		tree[cur_node].first = left_node;
		tree[cur_node].second = right_node;
	}
	for (int i = 0; i < MAX; i++) {
		low[i] = INF;
	}
	for (int i = 1; i <= N; i++) {
		if (node_cnt[i] == 1) {
			root = i;
			break;
		}
	}
	DFS(root, 1);

	for (int i = 1; i <= max_level; i++) {
		width = high[i] - low[i] + 1;
		if (max_width < width) {
			max_width = width;
			max_width_level = i;
		}
	}
	cout << max_width_level << " " << max_width;

	return 0;
}