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
		string s;
		cin >> s;
		int sum = 0;
		FOR(i, 0, 15) {
			if (i % 2 == 0) {
				int tmp = (s[i] - '0') * 2;
				if (tmp >= 10)
					sum += tmp / 10 + tmp % 10;
				else
					sum += tmp;
			}
			else if (i % 2 == 1) {
				sum += (s[i] - '0');
			}
		}
		if (sum % 10 == 0)
			cout << "T";
		else
			cout << "F";
		cout << "\n";
	}


	return 0;
}