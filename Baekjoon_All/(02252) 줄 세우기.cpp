#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v[32001];
int cnt[32001] = { 0, };
int ans[32001];

void TP() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0)
			q.push(i);
	}
	for (int i = 1; i <= N; i++) {
		int node = q.front();
		q.pop();
		ans[i] = node;
		int len = v[node].size();
		for (int j = 0; j < len; j++) {
			int new_node = v[node][j];
			cnt[new_node] -= 1;
			if (cnt[new_node] == 0)
				q.push(new_node);
		}
	}
}

int main() {
	int M;
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		cnt[b] += 1;
	}
	TP();
	for (int i = 1; i <= N; i++)
		cout << ans[i] << " ";

	return 0;
}