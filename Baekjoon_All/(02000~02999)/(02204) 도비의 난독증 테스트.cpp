#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[1001];

int main() {
	FASTIO;
	int N;
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		string s, mini;
		int pos = 1;
		FOR(i, 1, N) {
			cin >> s;
			arr[i] = s;
			int len = s.size();
			FOR(j, 0, len - 1) {
				if (s[j] >= 'a' && s[j] <= 'z') {
					s[j] = s[j] - 'a' + 'A';
				}
			}
			if (i == 1)
				mini = s;
			else {
				if (mini > s) {
					mini = s;
					pos = i;
				}
			}
		}
		cout << arr[pos] << "\n";
	}


	return 0;
}