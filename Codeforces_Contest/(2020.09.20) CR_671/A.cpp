#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[1001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		string s;
		int odd_cnt = 0;
		int even_cnt = 0;
		cin >> n;
		cin >> s;
		FOR(i, 0, n - 1) {
			if (i % 2 == 0) {
				int x = s[i] - '0';
				if (x % 2 == 1)
					odd_cnt++;
			}
			else if (i % 2 == 1) {
				int x = s[i] - '0';
				if (x % 2 == 0)
					even_cnt++;
			}
		}
		if (n % 2 == 1) {
			if (odd_cnt == 0)
				cout << 2;
			else
				cout << 1;
		}
		else if (n % 2 == 0) {
			if (even_cnt == 0)
				cout << 1;
			else
				cout << 2;
		}
		cout << "\n";
	}

	return 0;
}