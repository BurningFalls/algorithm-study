#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int h, m, s;
	int num;
	int tc;
	cin >> h >> m >> s;
	num = h * 3600 + m * 60 + s;
	cin >> tc;
	while (tc--) {
		int T, c;
		cin >> T;
		if (T == 2) {
			cin >> c;
			num -= c;
			while (num < 0)
				num += 86400;
		}
		else if (T == 1) {
			cin >> c;
			num += c;
			while (num >= 86400)
				num -= 86400;
		}
		else if (T == 3) {
			int temp = num;
			int H = temp / 3600;
			temp -= H * 3600;
			int M = temp / 60;
			temp -= M * 60;
			int S = temp;
			cout << H << " " << M << " " << S << "\n";
		}
	}

	return 0;
}