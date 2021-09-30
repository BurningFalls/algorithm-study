#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int arr[11][11];

int main() {
	FASTIO;
	int idx = 1;
	while (true) {
		int N;
		int sum = 0;
		cin >> N;
		if (N == 0)
			break;
		FOR(i, 1, N) {
			FOR(j, 1, i) {
				cin >> arr[i][j];
			}
		}
		FOR(i, 1, N) {
			sum += arr[i][1];
			sum += arr[N][i];
			sum += arr[i][i];
		}
		sum -= arr[1][1];
		sum -= arr[N][1];
		sum -= arr[N][N];
		if (N == 1)
			sum += arr[1][1];
		cout << "Case #" << idx << ":" << sum << "\n";
		idx++;
	}

	return 0;
}