#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

map<string, int> mp;
int pos[1001];
string ans[1001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	int N;
	string s;
	while (T--) {
		mp.clear();
		cin >> N;
		FOR(i, 1, N) {
			cin >> s;
			mp[s] = i;
		}
		FOR(i, 1, N) {
			cin >> s;
			pos[i] = mp[s];
		}
		FOR(i, 1, N) {
			cin >> s;
			ans[pos[i]] = s;
		}
		FOR(i, 1, N) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}