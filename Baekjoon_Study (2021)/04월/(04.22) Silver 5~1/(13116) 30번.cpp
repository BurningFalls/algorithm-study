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
		int A, B;
		cin >> A >> B;
		int Acnt = 0, Bcnt = 0;
		int ta = A, tb = B;
		while (ta != 1) {
			ta /= 2;
			Acnt++;
		}
		while (tb != 1) {
			tb /= 2;
			Bcnt++;
		}
		if (Acnt > Bcnt) {
			FOR(i, 1, Acnt - Bcnt)
				A /= 2;
		}
		else if (Acnt < Bcnt) {
			FOR(i, 1, Bcnt - Acnt)
				B /= 2;
		}
		int ans = 1;
		while (A != 1 && B != 1) {
			if (A == B) {
				ans = A;
				break;
			}
			A /= 2;
			B /= 2;
		}
		cout << 10 * ans << "\n";
	}



	return 0;
}