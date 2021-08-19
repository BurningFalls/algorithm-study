#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool arr[10001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N)
			cin >> arr[i];
		int idx = 0;
		ROF(i, N, 1) {
			if (arr[i] == 0) {
				idx = i;
				break;
			}
		}
		FOR(i, 1, idx)
			cout << i << " ";
		cout << N + 1 << " ";
		FOR(i, idx + 1, N)
			cout << i << " ";
		cout << "\n";
	}


	return 0;
}