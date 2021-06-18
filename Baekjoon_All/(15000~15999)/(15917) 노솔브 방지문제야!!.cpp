#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int Q;
	cin >> Q;
	FOR(i, 1, Q) {
		int a;
		cin >> a;
		bool flag = true;
		while (a != 1) {
			if (a % 2 == 1) {
				flag = false;
				break;
			}
			a /= 2;
		}
		cout << flag << "\n";
	}


	return 0;
}