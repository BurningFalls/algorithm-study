#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

vector<int> v;
int Parent[4000001];

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

void Union(int node1, int node2) {
	node1 = Find_Parent(node1);
	node2 = Find_Parent(node2);
	Parent[node1] = node2;
}

int main() {
	FASTIO;
	int N, M, K;
	int num;
	cin >> N >> M >> K;
	FOR(i, 0, M - 1)
		Parent[i] = i;
	FOR(i, 1, M) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	FOR(i, 1, K) {
		cin >> num;
		int ub = upper_bound(v.begin(), v.end(), num) - v.begin();
		ub = Find_Parent(ub);
		cout << v[ub] << "\n";
		Union(ub, ub + 1);
	}

	return 0;
}