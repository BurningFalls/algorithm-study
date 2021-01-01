#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
string s[100001];

int Compare(string s1, string s2) {
	int cnt = 0;
	FOR(i, 0, 3) {
		if (s1[i] != s2[i])
			cnt++;
	}
	return cnt;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		FOR(i, 1, N)
			cin >> s[i];
		if (N > 32)
			cout << 0;
		else {
			int minimum = 100;
			FOR(i, 1, N) {
				FOR(j, i + 1, N) {
					FOR(k, j + 1, N) {
						int temp = Compare(s[i], s[j]) + Compare(s[i], s[k]) + Compare(s[j], s[k]);
						minimum = min(minimum, temp);
					}
				}
			}
			cout << minimum;
		}
		cout << "\n";
	}

	return 0;
}