#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int Parent[200001];
int Friends[200001];
map<string, int> mp;

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

int is_Same(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	if (n1 == n2)
		return n1;
	else
		return -1;
}

int Union(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	Parent[n2] = n1;
	Friends[n1] += Friends[n2];
	return Friends[n1];
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		mp.clear();
		FOR(i, 1, 2 * N) {
			Parent[i] = i;
			Friends[i] = 1;
		}
		FOR(i, 1, N) {
			string a, b;
			int idx1, idx2;
			cin >> a >> b;
			if (mp.count(a))
				idx1 = mp[a];
			else {
				int len = mp.size();
				mp.insert({ a, len + 1 });
				idx1 = len + 1;
			}
			if (mp.count(b))
				idx2 = mp[b];
			else {
				int len = mp.size();
				mp.insert({ b, len + 1 });
				idx2 = len + 1;
			}
			int temp = is_Same(idx1, idx2);
			if (temp != -1) {
				cout << Friends[temp];
			}
			else {
				cout << Union(idx1, idx2);
			}
			cout << "\n";
		}
	}

	return 0;
}