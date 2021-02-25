#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

vector<pair<int, pii>> v;
int parent[200001];

int find_parent(int node) {
	if (parent[node] == node)
		return node;
	return parent[node] = find_parent(parent[node]);
}

bool Union(int n1, int n2) {
	n1 = find_parent(n1);
	n2 = find_parent(n2);
	if (n1 != n2) {
		parent[n1] = n2;
		return true;
	}
	else
		return false;
}

int main() {
	FASTIO;
	while (true) {
		int M, N;
		cin >> M >> N;
		if (M == 0 && N == 0)
			break;
		int sum = 0;
		v.clear();
		FOR(i, 0, M - 1)
			parent[i] = i;
		int x, y, z;
		FOR(i, 1, N) {
			cin >> x >> y >> z;
			v.push_back({ z, {x, y} });
			sum += z;
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		int ans = 0;
		FOR(i, 0, N - 1) {
			int cost = v[i].first;
			int n1 = v[i].second.first;
			int n2 = v[i].second.second;
			if (Union(n1, n2)) {
				cnt++;
				ans += cost;
			}
			if (cnt == M - 1)
				break;
		}
		cout << sum - ans << "\n";
	}


	return 0;
}