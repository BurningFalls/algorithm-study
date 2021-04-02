#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, L;
	cin >> N >> L;
	int idx = 1;
	int cnt = 0;
	while (cnt < N) {
		string s = to_string(idx);
		int len = s.size();
		bool flag = true;
		FOR(i, 0, len - 1) {
			if (s[i] - '0' == L) {
				flag = false;
				break;
			}
		}
		if (flag)
			cnt++;
		idx++;
	}
	cout << idx - 1;

	return 0;
}