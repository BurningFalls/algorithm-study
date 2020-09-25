#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	vector<int> v;
	int N;
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		v.push_back(N);
	}
	FOR(k, 0, v.size() - 1) {
		N = v[k];
		if (N == 0)
			break;
		int ans = 0;
		FOR(i, 0, 98) {
			int temp = i * (i + 1) * (i + 2) / 6;
			if (temp > N)
				break;
			int t = 0;
			FOR(j, 0, 41) {
				if (N - temp >= j * j * j && N - temp < (j + 1) * (j + 1) * (j + 1)) {
					t = j;
					break;
				}
			}
			ans = max(ans, temp + t * t * t);
		}
		cout << ans;
		if (k != v.size() - 1)
			cout << "\n";
	}

	return 0;
}