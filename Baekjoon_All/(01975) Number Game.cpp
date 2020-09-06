#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int cnt[1001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		int cnt = 0;
		cin >> N;
		FOR(i, 2, N) {
			if (N % i == 0) {
				int temp = N;
				while (temp % i == 0) {
					temp /= i;
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}