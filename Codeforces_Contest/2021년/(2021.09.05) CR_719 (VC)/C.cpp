#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N == 2) {
			cout << "-1\n";
			continue;
		}
		int num1 = N + 1;
		int num2 = N + 2;
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j)
					cout << i;
				else if (i < j) {
					cout << num1;
					num1 += 2;
				}
				else if (i > j) {
					cout << num2;
					num2 += 2;
				}
				cout << " ";
			}
			cout << "\n";
		}
	}


	return 0;
}