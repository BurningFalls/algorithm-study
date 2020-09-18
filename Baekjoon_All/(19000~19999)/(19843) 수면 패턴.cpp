#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

string s[6] = { "Mon", "Tue", "Wed", "Thu", "Fri" };

int main() {
	FASTIO;
	int T, N;
	cin >> T >> N;
	int ans = 0;
	FOR(i, 1, N) {
		string d1, d2;
		int h1, h2;
		cin >> d1 >> h1 >> d2 >> h2;
		int a, b;
		FOR(j, 0, 4) {
			if (s[j] == d1) {
				a = j;
				break;
			}
		}
		FOR(j, 0, 4) {
			if (s[j] == d2) {
				b = j;
				break;
			}
		}
		if (a == b) {
			ans += (h2 - h1);
		}
		else if (a != b) {
			ans += 24 * (b - a) + (h2 - h1);
		}
	}
	int temp = T - ans;
	if (temp < 0)
		cout << 0;
	else if (temp >= 0 && temp <= 48)
		cout << temp;
	else {
		cout << -1;
	}
	cout << "\n";

	return 0;
}