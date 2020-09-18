#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int A[10001];
int Parent[10001];
bool visited[10001] = { 0, };

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

bool Is_Same(int node1, int node2) {
	node1 = Find_Parent(node1);
	node2 = Find_Parent(node2);
	return node1 == node2;
}

void Union(int node1, int node2) {
	node1 = Find_Parent(node1);
	node2 = Find_Parent(node2);
	if (A[node1] <= A[node2])
		Parent[node2] = node1;
	else if (A[node1] > A[node2])
		Parent[node1] = node2;
}

int main() {
	FASTIO;
	int N, M, K;
	int total_cost = 0;
	cin >> N >> M >> K;
	FOR(i, 1, N)
		cin >> A[i];
	FOR(i, 1, N)
		Parent[i] = i;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		if (!Is_Same(a, b))
			Union(a, b);
	}
	FOR(i, 1, N) {
		int parent = Find_Parent(i);
		if (visited[parent]) continue;
		visited[parent] = 1;
		total_cost += A[parent];
	}
	if (total_cost <= K)
		cout << total_cost;
	else
		cout << "Oh no";

	return 0;
}