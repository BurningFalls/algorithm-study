#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	FOR(i, 100, 999) {
		FOR(j, 100, 999) {
			int x = i % 10;
			int y = j / 100;
			if (x != y) continue;
			bool flag = false;
			FOR(k, 1, 9) {
				int temp = 111 * k;
				if (i == temp && j == temp) {
					flag = true;
					break;
				}
			}
			if (flag)
				continue;
			int a, b;
			a = i / 10;
			b = j % 100;
			if (i * b == j * a) {
				cout << i << " / " << j << " = " << a << " / " << b << "\n";
			}
		}
	}

	return 0;
}