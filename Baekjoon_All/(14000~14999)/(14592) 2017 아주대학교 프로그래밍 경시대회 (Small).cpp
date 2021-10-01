#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

struct NODE {
	int S;
	int C;
	int L;
	int idx;
};

bool cmp(NODE a, NODE b) {
	if (a.S == b.S) {
		if (a.C == b.C) {
			return a.L < b.L;
		}
		return a.C < b.C;
	}
	return a.S > b.S;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<NODE> v;
	FOR(i, 1, N) {
		int S, C, L;
		cin >> S >> C >> L;
		v.push_back({ S, C, L, i });
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].idx;

	return 0;
}