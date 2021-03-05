#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int L, R;
	cin >> L >> R;
	string sL = to_string(L);
	string sR = to_string(R);
	int lenL = sL.size();
	int lenR = sR.size();
	if (lenL == lenR) {
		int cnt = 0;
		FOR(i, 0, lenL - 1) {
			if (sL[i] != sR[i]) {
				break;
			}
			if (sL[i] == '8' && sR[i] == '8')
				cnt++;
		}
		cout << cnt;
	}
	else {
		cout << 0;
	}


	return 0;
}