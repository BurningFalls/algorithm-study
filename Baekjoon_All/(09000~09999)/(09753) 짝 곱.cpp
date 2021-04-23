#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool not_Prime[100002] = { 0, };
bool multi[100002] = { 0, };

void Find_Prime() {
	not_Prime[1] = 1;
	FOR(i, 2, 100001) {
		if (not_Prime[i]) continue;
		for (int j = 2 * i; j <= 100001; j += i) {
			not_Prime[j] = 1;
		}
	}
}

int main() {
	FASTIO;
	Find_Prime();
	FOR(i, 6, 100001) {
		if (i % 2 == 0) {
			if (not_Prime[i / 2]) continue;
			multi[i] = 1;
		}
		else if (i % 2 == 1) {
			int tmp = sqrt(i);
			FOR(j, 3, tmp) {
				if (not_Prime[j]) continue;
				if (i % j != 0) continue;
				if (j == (i / j)) continue;
				if (not_Prime[i / j]) continue;
				multi[i] = 1;
				break;
			}
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int K;
		cin >> K;
		while (!multi[K]) {
			K++;
		}
		cout << K << "\n";
	}


	return 0;
}