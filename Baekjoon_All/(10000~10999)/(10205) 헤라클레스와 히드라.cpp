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
	int T;
	cin >> T;
	FOR(t, 1, T) {
		int H;
		string s;
		cin >> H >> s;
		int bcnt = 0;
		int ccnt = 0;
		FOR(i, 0, LEN(s) - 1) {
			if (s[i] == 'b') {
				bcnt++;
			}
			else if (s[i] == 'c') {
				ccnt++;
			}
		}
		H = H - bcnt + ccnt;
		cout << "Data Set " << t << ":\n";
		cout << H << "\n\n";
	}


	return 0;
}