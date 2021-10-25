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
	while (T--) {
		int N;
		cin >> N;
		string s;
		cin >> s;
		int ans = INF;
		FOR(idx, 0, 25) {
			int left = 0, right = N - 1;
			int cnt = 0;
			char x = idx + 'a';
			bool flag = true;
			while (left < right) {
				if (s[left] == s[right]) {
					left++;
					right--;
				}
				else if (s[left] != s[right]) {
					if (s[left] == x) {
						cnt++;
						left++;
					}
					else if (s[right] == x) {
						cnt++;
						right--;
					}
					else {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				ans = min(ans, cnt);
			}
		}
		cout << (ans != INF ? ans : -1) << "\n";
	}


	return 0;
}