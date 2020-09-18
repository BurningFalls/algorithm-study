#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int G, P;
int gi[100001];
int Parent[100001];

int Find(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find(Parent[node]);
}

void Union(int node1, int node2) {
	node1 = Parent[node1];
	node2 = Parent[node2];
	Parent[node1] = node2;
}

int main() {
	FASTIO;
	int ans = 0;
	cin >> G >> P;
	FOR(i, 1, P)
		cin >> gi[i];
	FOR(i, 1, G)
		Parent[i] = i;
	FOR(i, 1, P) {
		int temp = Find(gi[i]);
		if (temp != 0) {
			ans++;
			Union(temp, temp - 1);
		}
		else
			break;
	}
	cout << ans;

	return 0;
}