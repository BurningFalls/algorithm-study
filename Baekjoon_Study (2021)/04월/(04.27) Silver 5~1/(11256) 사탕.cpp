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
		int J, N;
		vector<int> v;
		cin >> J >> N;
		FOR(i, 1, N) {
			int R, C;
			cin >> R >> C;
			v.push_back(R * C);
		}
		sort(v.begin(), v.end(), greater<int>());
		int sum = 0;
		int cnt = 0;
		FOR(i, 0, N - 1) {
			sum += v[i];
			cnt++;
			if (sum >= J)
				break;
		}
		cout << cnt << "\n";
	}



	return 0;
}