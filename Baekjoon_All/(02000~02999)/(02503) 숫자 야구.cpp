#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool pos[1001] = { 0, };

void Cmp(string a, string b, int* sc, int* bc) {
	FOR(i, 0, 2) {
		FOR(j, 0, 2) {
			if (a[i] == b[j]) {
				if (i == j)
					(*sc)++;
				else if (i != j)
					(*bc)++;
			}
		}
	}
}

int main() {
	FASTIO;
	FOR(i, 100, 999) {
		string s = to_string(i);
		if (s[0] == '0' || s[1] == '0' || s[2] == '0') continue;
		if (s[0] == s[1] || s[1] == s[2] || s[2] == s[0]) continue;
		pos[i] = 1;
	}
	int N;
	cin >> N;
	FOR(t, 1, N) {
		int Q, S, B;
		cin >> Q >> S >> B;
		FOR(i, 100, 999) {
			if (!pos[i]) continue;
			int s_cnt = 0;
			int b_cnt = 0;
			string qs = to_string(Q);
			string temp = to_string(i);
			if (temp == "123")
				int a = 1;
			Cmp(qs, temp, &s_cnt, &b_cnt);
			if (!(s_cnt == S && b_cnt == B))
				pos[i] = 0;
		}
	}
	int ans = 0;
	FOR(i, 100, 999) {
		if (pos[i])
			ans++;
	}
	cout << ans;

	return 0;
}