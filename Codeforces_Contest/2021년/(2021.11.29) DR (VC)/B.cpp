#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int N, Q;
	string s;
	cin >> N >> Q;
	cin >> s;
	int cnt = 0;;
	FOR(i, 0, LEN(s) - 3) {
		if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
			cnt++;
		}
	}
	FOR(q, 1, Q) {
		int idx;
		char ch;
		cin >> idx >> ch;
		idx -= 1;
		if (s[idx] == 'a') {
			if (idx + 2 < LEN(s) && s[idx + 1] == 'b' && s[idx + 2] == 'c') {
				cnt--;
			}
		}
		else if (s[idx] == 'b') {
			if (idx - 1 >= 0 && idx + 1 < LEN(s) && s[idx - 1] == 'a' && s[idx + 1] == 'c') {
				cnt--;
			}
		}
		else if (s[idx] == 'c') {
			if (idx - 2 >= 0 && s[idx - 2] == 'a' && s[idx - 1] == 'b') {
				cnt--;
			}
		}
		s[idx] = ch;
		if (s[idx] == 'a') {
			if (idx + 2 < LEN(s) && s[idx + 1] == 'b' && s[idx + 2] == 'c') {
				cnt++;
			}
		}
		else if (s[idx] == 'b') {
			if (idx - 1 >= 0 && idx + 1 < LEN(s) && s[idx - 1] == 'a' && s[idx + 1] == 'c') {
				cnt++;
			}
		}
		else if (s[idx] == 'c') {
			if (idx - 2 >= 0 && s[idx - 2] == 'a' && s[idx - 1] == 'b') {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}



	return 0;
}