#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	string s;
	int N;
	while (true) {
		cin >> s >> N;
		if (s == "#" && N == 0)
			break;
		int ans = N;
		while (true) {
			char x;
			int num;
			cin >> x >> num;
			if (x == 'X' && num == 0)
				break;
			if (x == 'B') {
				if (ans + num <= 68)
					ans += num;
			}
			else if (x == 'C') {
				if (ans - num >= 0)
					ans -= num;
			}
		}
		cout << s << " " << ans << "\n";
	}

	return 0;
}