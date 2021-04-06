#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct INF {
	int kb;
	int tim;
	char x;
};

vector<INF> v;

bool cmp(INF a, INF b) {
	if (a.tim == b.tim)
		return a.kb < b.kb;
	return a.tim < b.tim;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		INF tmp = { a, b, c };
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);
	for (INF node : v) {
		cout << node.x;
	}

	return 0;
}