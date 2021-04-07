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
		int B;
		string D;
		cin >> B >> D;
		int len = D.size();
		int sum = 0;
		FOR(i, 0, len - 1) {
			sum += (D[i] - '0') % (B - 1);
		}
		cout << sum % (B - 1) << "\n";
	}


	return 0;
}