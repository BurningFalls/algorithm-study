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
		int arr[3], m;
		FOR(i, 0, 2)
			cin >> arr[i];
		cin >> m;
		sort(arr, arr + 3);
		int mini = max(0, arr[2] - (arr[0] + arr[1] + 1));
		int maxi = arr[0] + arr[1] + arr[2] - 3;
		cout << ((mini <= m && m <= maxi) ? "YES" : "NO") << "\n";
	}

	return 0;
}