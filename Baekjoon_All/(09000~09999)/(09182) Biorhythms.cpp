#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int a, b, c, d;
	int idx = 1;
	while (true) {
		cin >> a >> b >> c >> d;
		if (a == -1 && b == -1 && c == -1 && d == -1)
			break;
		int temp = 0;
		FOR(i, 0, 644) {
			if ((33 * i + c - b) < 0 || (33 * i + c - a) < 0) continue;
			if ((33 * i + c - b) % 28 == 0 && ((33 * i + c - a) % 23 == 0)) {
				temp = 33 * i + c;
				break;
			}
		}
		if (temp == 0)
			temp = 21252;
		cout << "Case " << idx << ": the next triple peak occurs in ";
		cout << temp - d << " days.\n";
		idx++;
	}

	return 0;
}