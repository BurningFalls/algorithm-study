#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[101];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N)
			cin >> arr[i];
		char prev = '?';
		FOR(i, 1, N) {
			if (arr[i] == 'R' || arr[i] == 'B') {
				prev = arr[i];
				continue;
			}
			if (prev == '?') continue;
			arr[i] = ((prev == 'B') ? 'R' : 'B');
			prev = arr[i];
		}
		prev = 'R';
		ROF(i, N, 1) {
			if (arr[i] == 'R' || arr[i] == 'B') {
				prev = arr[i];
				continue;
			}
			if (prev == '?') continue;
			arr[i] = ((prev == 'B') ? 'R' : 'B');
			prev = arr[i];
		}
		FOR(i, 1, N)
			cout << arr[i];
		cout << "\n";
	}


	return 0;
}