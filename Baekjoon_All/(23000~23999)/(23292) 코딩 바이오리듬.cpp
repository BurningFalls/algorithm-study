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

int main() {
	FASTIO;
	string birth;
	int N;
	cin >> birth;
	cin >> N;
	int maxi = -1;
	string ans = "";
	FOR(n, 1, N) {
		string s;
		cin >> s;
		int sum1 = 0, sum2 = 0, sum3 = 0;
		FOR(i, 0, 3) {
			sum1 += (birth[i] - s[i]) * (birth[i] - s[i]);
		}
		FOR(i, 4, 5) {
			sum2 += (birth[i] - s[i]) * (birth[i] - s[i]);
		}
		FOR(i, 6, 7) {
			sum3 += (birth[i] - s[i]) * (birth[i] - s[i]);
		}
		if (maxi < sum1 * sum2 * sum3) {
			maxi = sum1 * sum2 * sum3;
			ans = s;
		}
		else if (maxi == sum1 * sum2 * sum3) {
			ans = min(ans, s);
		}
	}
	cout << ans;

	return 0;
}