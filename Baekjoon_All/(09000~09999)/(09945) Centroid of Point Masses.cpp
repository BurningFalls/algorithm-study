#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	cout << fixed << setprecision(2);
	int idx = 1;
	while (true) {
		int N;
		double m_sum = 0, mx_sum = 0, my_sum = 0;
		cin >> N;
		if (N < 0)
			break;
		FOR(i, 1, N) {
			double x, y, m;
			cin >> x >> y >> m;
			m_sum += m;
			mx_sum += m * x;
			my_sum += m * y;
		}
		cout << "Case " << idx << ": ";
		cout << mx_sum / m_sum << " " << my_sum / m_sum << "\n";
		idx++;
	}

	return 0;
}