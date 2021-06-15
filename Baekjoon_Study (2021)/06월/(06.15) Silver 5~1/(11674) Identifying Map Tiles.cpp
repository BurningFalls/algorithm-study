#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string s;
int len;

int main() {
	FASTIO;
	cin >> s;
	len = s.size();
	int y = 0, x = 0;
	FOR(i, 0, len - 1) {
		y *= 2;
		x *= 2;
		if (s[i] == '1') {
			x += 1;
		}
		else if (s[i] == '2') {
			y += 1;
		}
		else if (s[i] == '3') {
			x += 1;
			y += 1;
		}
	}
	cout << len << " " << x << " " << y;


	return 0;
}