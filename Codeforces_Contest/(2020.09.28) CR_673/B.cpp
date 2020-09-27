#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];

int main() {
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int n, T;
		cin >> n >> T;
		int cnt = 0;
		FOR(i, 1, n)
			cin >> arr[i];
		if (T % 2 == 0) {
			FOR(i, 1, n) {
				if (arr[i] > T / 2)
					cout << "1 ";
				else if (arr[i] < T / 2)
					cout << "0 ";
				else if (arr[i] == T / 2) {
					cout << cnt % 2 << " ";
					cnt++;
				}
			}
		}
		else if (T % 2 == 1) {
			FOR(i, 1, n) {
				if (arr[i] > T / 2)
					cout << "1 ";
				else if (arr[i] <= T / 2)
					cout << "0 ";
			}
		}
		cout << "\n";
	}

	return 0;
}