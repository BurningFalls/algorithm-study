#include <iostream>
#include <vector>
using namespace std;

int delete_node;
vector<int> child[51];
int leaf_cnt = 0;

void DFS(int node) {
	int next_node;
	int len, len_cnt;
	len = child[node].size();
	len_cnt = len;
	for (int i = 0; i < len; i++) {
		next_node = child[node][i];
		if (next_node == delete_node) {
			len_cnt--;
			continue;
		}
		DFS(next_node);
	}
	if (len_cnt == 0) {
		leaf_cnt++;
		return;
	}
}

int main() {
	int N;
	int num;
	int root = 0;
	cin >> N;
	for (int node = 0; node < N; node++) {
		cin >> num;
		if (num == -1) {
			root = node;
			continue;
		}
		child[num].push_back(node);
	}
	cin >> delete_node;

	if (delete_node == root)
		cout << 0;
	else {
		DFS(root);
		cout << leaf_cnt;
	}

	return 0;
}