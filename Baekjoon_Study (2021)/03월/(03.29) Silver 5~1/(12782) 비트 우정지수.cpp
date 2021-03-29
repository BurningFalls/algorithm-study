#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string N, M;
		cin >> N >> M;
		int zero_cnt = 0;
		int one_cnt = 0;
		int len = N.size();
		FOR(i, 0, len - 1) {
			if (N[i] == '1' && M[i] == '0') {
				one_cnt++;
			}
			else if (N[i] == '0' && M[i] == '1') {
				zero_cnt++;
			}
		}
		cout << max(zero_cnt, one_cnt) << "\n";
	}


	return 0;
}