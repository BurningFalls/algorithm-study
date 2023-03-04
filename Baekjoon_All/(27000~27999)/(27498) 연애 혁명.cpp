#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 10001

struct NODE {
	int a;
	int b;
	int c;
	bool operator<(const NODE& n) const {
		return c > n.c;
	}
};

int N, M;
vector<NODE> v;
vector<int> Parent(MAX);

int Find(int node) {
	if (Parent[node] == node) {
		return node;
	}
	return Parent[node] = Find(Parent[node]);
}

bool is_Same(int n1, int n2) {
	n1 = Find(n1);
	n2 = Find(n2);
	return n1 == n2;
}

void Union(int n1, int n2) {
	n1 = Find(n1);
	n2 = Find(n2);
	Parent[n1] = n2;
}

int main() {
	FASTIO;
	int total = 0;
	int sum = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		Parent[i] = i;
	}
	FOR(i, 0, M - 1) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		total += c;
		if (d == 1) {
			Union(a, b);
			sum += c;
		}
		else if (d == 0) {
			v.push_back({ a, b, c });
		}
	}
	sort(ALL(v));

	FOR(i, 0, LEN(v) - 1) {
		if (!is_Same(v[i].a, v[i].b)) {
			Union(v[i].a, v[i].b);
			sum += v[i].c;
		}
	}

	cout << total - sum;

	return 0;
}