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
		int zero_cnt = 0;
		int one_cnt = 0;
		cin >> n;
		FOR(i, 1, n) {
			cin >> arr[i];
			if (arr[i] == 0)
				zero_cnt++;
			else if (arr[i] == 1)
				one_cnt++;
		}
		if (zero_cnt >= one_cnt) {
			cout << n / 2 << "\n";
			FOR(i, 1, n / 2)
				cout << "0 ";
		}
		else if (zero_cnt < one_cnt) {
			if ((n / 2) % 2 == 0) {
				cout << n / 2 << "\n";
				FOR(i, 1, n / 2)
					cout << "1 ";
			}
			else if ((n / 2) % 2 == 1) {
				cout << n / 2 + 1 << "\n";
				FOR(i, 1, n / 2 + 1)
					cout << "1 ";
			}
		}
		cout << "\n";
	}

	return 0;
}