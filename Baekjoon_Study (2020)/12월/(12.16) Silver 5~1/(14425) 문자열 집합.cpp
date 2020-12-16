#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

set<string> S;

int main() {
	FASTIO;
	int N, M;
	int cnt = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		S.insert(s);
	}
	FOR(i, 1, M) {
		string s;
		cin >> s;
		if (S.count(s))
			cnt++;
	}
	cout << cnt;

	return 0;
}