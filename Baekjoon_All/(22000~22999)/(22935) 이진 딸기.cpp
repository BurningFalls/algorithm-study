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
		cin >> N;
		N = (N - 1) % 28 + 1;
		string tmp = "";
		if (N >= 16)
			N = 30 - N;
		while (N) {
			tmp += (N % 2) + '0';
			N /= 2;
		}
		int len = tmp.size();
		FOR(i, 1, 4 - len)
			tmp += '0';
		ROF(i, 3, 0) {
			if (tmp[i] == '0')
				cout << "V";
			else
				cout << "µþ±â";
		}
		cout << "\n";
	}


	return 0;
}