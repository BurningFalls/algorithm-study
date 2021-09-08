#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

ll arr[200003];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N + 2)
			cin >> arr[i];
		sort(arr + 1, arr + N + 3);
		ll sum = 0;
		FOR(i, 1, N) {
			sum += arr[i];
		}
		if (sum == arr[N + 1]) {
			FOR(i, 1, N) {
				cout << arr[i] << " ";
			}
		}
		else {
			sum += arr[N + 1];
			int idx = 0;
			FOR(i, 1, N + 1) {
				sum -= arr[i];
				if (sum == arr[N + 2]) {
					idx = i;
					break;
				}
				sum += arr[i];
			}
			if (idx == 0) {
				cout << -1;
			}
			else {
				FOR(i, 1, N + 1) {
					if (idx == i) continue;
					cout << arr[i] << " ";
				}
			}
		}
		cout << "\n";
	}

	return 0;
}