#include <bits/stdc++.h>
using namespace std;

int N, K;
int D[1001];
vector<int> v[1001];
int cnt[1001] = { 0, };
int timing[1001] = { 0, };

int TP(int end) {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0)
			q.push(i);
	}
	while (cnt[end] > 0) {
		int node = q.front();
		q.pop();
		int len = v[node].size();
		for (int i = 0; i < len; i++) {
			int new_node = v[node][i];
			timing[new_node] = max(timing[new_node], timing[node] + D[node]);
			cnt[new_node]--;
			if (cnt[new_node] == 0)
				q.push(new_node);
		}
	}
	return timing[end] + D[end];
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int X, Y, W;
		for (int i = 1; i <= N; i++) {
			v[i].clear();
			cnt[i] = 0;
			timing[i] = 0;
		}
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
			cin >> D[i];
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			v[X].push_back(Y);
			cnt[Y]++;
		}
		cin >> W;
		cout << TP(W) << "\n";
	}

	return 0;
}