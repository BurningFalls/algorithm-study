#include <bits/stdc++.h>
using namespace std;

int n;
int a[200001];
int b[200001];
vector<int> v[200001];
int cnt[200001];
int result[200001];
int sum = 0;

void Func() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0)
			q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		int node = q.front();
		q.pop();
		result[i] = node;
		sum += a[node];
		if (b[node] != -1)
			a[b[node]] += a[node];
		for (int i = 0; i < v[node].size(); i++) {
			int new_node = v[node][i];
			if (--cnt[new_node] == 0)
				q.push(new_node);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		v[i].clear();
		cnt[i] = 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++) {
		if (b[i] == -1) continue;
		if (a[i] > 0) {
			v[i].push_back(b[i]);
			cnt[b[i]]++;
		}
		else if (a[i] < 0) {
			v[b[i]].push_back(i);
			cnt[i]++;
		}
	}
	Func();
	cout << sum << "\n";
	for (int i = 1; i <= n; i++)
		cout << result[i] << " ";

	return 0;
}