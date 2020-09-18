#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[32001];
vector<int> v[32001];
int cnt[32001] = { 0, };
int ans[32001];

void TP() {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0)
			pq.push(i);
	}
	for (int i = 1; i <= N; i++) {
		int node = pq.top();
		pq.pop();
		ans[i] = node;
		int len = v[node].size();
		for (int j = 0; j < len; j++) {
			int new_node = v[node][j];
			cnt[new_node]--;
			if (cnt[new_node] == 0)
				pq.push(new_node);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		cnt[b]++;
	}
	TP();
	for (int i = 1; i <= N; i++)
		cout << ans[i] << " ";

	return 0;
}