#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 200001

typedef struct _NODE {
	int x;
	int b;
	int c;
	int d;
} NODE;

int N, Q;
int arr[MAX];
int Parent[MAX];
vector<NODE> quest;
vector<string> ans;

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

bool is_Same(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	return (n1 == n2);
}

void Union(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	Parent[n2] = n1;
}

int main() {
	FASTIO;
	cin >> N >> Q;
	FOR(i, 1, N)
		Parent[i] = i;
	FOR(i, 2, N) {
		int num;
		cin >> num;
		arr[i] = num;
	}
	FOR(t, 1, N - 1 + Q) {
		int x;
		cin >> x;
		if (x == 0) {
			int b;
			cin >> b;
			quest.push_back({ x, b, 0, 0 });
		}
		else if (x == 1) {
			int c, d;
			cin >> c >> d;
			quest.push_back({ x, 0, c, d });
		}
	}
	ROF(i, N - 2 + Q, 0) {
		int x = quest[i].x;
		if (x == 0) {
			int b = quest[i].b;
			if (is_Same(arr[b], b)) continue;
			Union(arr[b], b);
		}
		else if (x == 1) {
			int c = quest[i].c;
			int d = quest[i].d;
			ans.push_back((is_Same(c, d) ? "YES" : "NO"));
		}
	}
	ROF(i, Q - 1, 0)
		cout << ans[i] << "\n";

	return 0;
}