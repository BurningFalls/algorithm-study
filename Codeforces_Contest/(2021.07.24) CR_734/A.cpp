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
		N -= 1;
		if (N % 3 == 0) {
			cout << N / 3 + 1 << " " << N / 3;
		}
		else if (N % 3 == 1) {
			cout << N / 3 << " " << N / 3 + 1;
		}
		else if (N % 3 == 2) {
			cout << N / 3 + 1 << " " << N / 3 + 1;
		}
		cout << "\n";
	}


	return 0;
}