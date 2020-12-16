#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		string s1, s2;
		cin >> N;
		cin >> s1 >> s2;
		int cnt1 = 0, cnt2 = 0;
		FOR(i, 0, N - 1) {
			if (s1[i] == 'B' && s2[i] == 'W')
				cnt1++;
			else if (s1[i] == 'W' && s2[i] == 'B')
				cnt2++;
		}
		int Min = min(cnt1, cnt2);
		cout << Min + (cnt1 - Min) + (cnt2 - Min) << "\n";
	}

	return 0;
}