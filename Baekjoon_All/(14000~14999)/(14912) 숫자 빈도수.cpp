#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int cnt[10] = { 0, };
	int n, d;
	cin >> n >> d;
	FOR(i, 1, n) {
		string s = to_string(i);
		int len = s.size();
		FOR(j, 0, len - 1) {
			cnt[s[j] - '0']++;
		}
	}
	cout << cnt[d];


	return 0;
}