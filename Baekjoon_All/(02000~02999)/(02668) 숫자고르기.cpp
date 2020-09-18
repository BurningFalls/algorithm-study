#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[101];
vector<bool> sub_visited(101, 0);
vector<bool> visited(101, 0);
vector<int> sub_ans;
vector<int> ans;

void DFS(int start, int n) {
	if (sub_visited[n]) {
		if (start == n) {
			for (int i = 0; i < sub_ans.size(); i++) {
				visited[sub_ans[i]] = 1;
				ans.push_back(sub_ans[i]);
			}
		}
		sub_visited = vector<bool>(101, 0);
		sub_ans.clear();
		return;
	}
	sub_visited[n] = 1;
	sub_ans.push_back(n);
	DFS(start, arr[n]);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		sub_visited[i] = 1;
		sub_ans.push_back(i);
		DFS(i, arr[i]);
	}

	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}