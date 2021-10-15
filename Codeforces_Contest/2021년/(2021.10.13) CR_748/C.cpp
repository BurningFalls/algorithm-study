#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		vector<int> mice(K);
		FOR(i, 0, K - 1) {
			cin >> mice[i];
		}
		sort(ALL(mice));
		int cat = 0;
		int cnt = 0;
		ROF(i, K - 1, 0) {
			if (cat >= mice[i])
				break;
			cat += N - mice[i];
			cnt++;
		}
		P1(cnt);
	}


	return 0;
}