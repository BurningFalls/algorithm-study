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
	int idx = 1;
	cin >> T;
	cout << fixed << setprecision(9);
	while (T--) {
		cout << "Case " << idx << ": ";
		int N;
		double min_x, min_y, max_x, max_y;
		min_x = 1001, min_y = 1001;
		max_x = -1001, max_y = -1001;
		cin >> N;
		FOR(i, 1, N) {
			double x, y;
			cin >> x >> y;
			min_x = min(min_x, x);
			min_y = min(min_y, y);
			max_x = max(max_x, x);
			max_y = max(max_y, y);
		}
		cout << "Area ";
		cout << (max_y - min_y) * (max_x - min_x);
		cout << ", Perimeter ";
		cout << 2 * (max_y - min_y + max_x - min_x);
		cout << "\n";
		idx++;
	}

	return 0;
}