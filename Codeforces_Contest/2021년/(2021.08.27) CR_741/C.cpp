#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[20001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int idx = 0;
		FOR(i, 1, N)
			cin >> arr[i];
		FOR(i, 1, N) {
			if (arr[i] == '0') {
				idx = i;
				break;
			}
		}
		if (idx == 0) {
			cout << 1 << " " << (N / 2) * 2 << " ";
			cout << 1 << " " << N / 2 << "\n";
		}
		else if (idx <= (N + 1) / 2) {
			cout << idx << " " << N << " ";
			cout << idx + 1 << " " << N << "\n";
		}
		else {
			cout << 1 << " " << idx << " ";
			cout << 1 << " " << idx - 1 << "\n";
		}
	}


	return 0;
}