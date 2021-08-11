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
		double s1 = 0, s2 = 0, s3 = 0;
		FOR(i, 1, 10) {
			double a, b, c;
			cin >> a >> b >> c;
			s1 += a;
			s2 += b;
			s3 += c;
		}
		cout << round(s1 / 10) << " " << round(s2 / 10) << " " << round(s3 / 10) << "\n";
	}


	return 0;
}