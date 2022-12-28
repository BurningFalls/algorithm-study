#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	cin.ignore();
	FOR(t, 1, N) {
		string s;
		getline(cin, s);
		s += ' ';
		string tmp = "";
		vector<string> v;
		FOR(i, 0, LEN(s) - 1) {
			if (s[i] == ' ') {
				v.push_back(tmp);
				tmp = "";
			}
			else {
				tmp += s[i];
			}
		}
		cout << "Case #" << t << ": ";
		ROF(i, LEN(v) - 1, 0) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}