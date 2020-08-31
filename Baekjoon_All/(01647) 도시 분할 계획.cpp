#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, M;
int Parent[100001];
vector<pair<int, pair<int, int>>> v;

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

bool Same_Parent(int node1, int node2) {
	int temp1 = Find_Parent(node1);
	int temp2 = Find_Parent(node2);
	return temp1 == temp2;
}

void Union(int node1, int node2) {
	int temp1 = Find_Parent(node1);
	int temp2 = Find_Parent(node2);
	if (temp1 != temp2)
		Parent[temp2] = temp1;
}

int main() {
	FASTIO;
	int ans = 0;
	cin >> N >> M;
	FOR(i, 1, M) {
		int A, B, C;
		cin >> A >> B >> C;
		v.push_back({ C, {A, B} });
	}
	sort(v.begin(), v.end());
	FOR(i, 1, N)
		Parent[i] = i;
	int cnt = 0;
	FOR(i, 0, M - 1) {
		int node1 = v[i].second.first;
		int node2 = v[i].second.second;
		int cost = v[i].first;
		if (!Same_Parent(node1, node2)) {
			Union(node1, node2);
			ans += cost;
			cnt++;
			if (cnt == N - 2)
				break;
		}
	}
	cout << ans;

	return 0;
}