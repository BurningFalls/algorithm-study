#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int Parent[101];
vector<pair<double, double>> v;
priority_queue<pair<double, pair<int, int>>> pq;

double Dist(int a, int b) {
	return sqrt(pow((v[a].first - v[b].first), 2) + pow((v[a].second - v[b].second), 2));
}

int Find(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find(Parent[node]);
}

bool Is_Same(int node1, int node2) {
	node1 = Find(node1);
	node2 = Find(node2);
	return node1 == node2;
}

void Union(int node1, int node2) {
	node1 = Find(node1);
	node2 = Find(node2);
	Parent[node2] = node1;
}

int main() {
	FASTIO;
	int n;
	double ans = 0;
	cin >> n;
	FOR(i, 0, n - 1) {
		double a, b;
		cin >> a >> b;
		v.push_back({ a, b });
		Parent[i] = i;
	}
	FOR(i, 0, n - 1) {
		FOR(j, i + 1, n - 1) {
			pq.push({ -Dist(i, j), {i, j} });
		}
	}
	int cnt = 0;
	while(cnt < n - 1) {
		double dist = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (!Is_Same(x, y)) {
			Union(x, y);
			ans += dist;
			cnt++;
		}
	}
	cout << fixed << setprecision(2);
	cout << ans;

	return 0;
}