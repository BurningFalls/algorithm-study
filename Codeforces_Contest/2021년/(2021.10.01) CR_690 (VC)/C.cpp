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
	int ans[51];
	MEMSET(ans, -1);

	int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	FOR(i, 1, (1 << 9) - 1) {
		int sum = 0;
		string s = "";
		FOR(j, 0, 8) {
			if (i & (1 << j)) {
				sum += arr[j];
				s += (arr[j] + '0');
			}
		}
		int num = stoi(s);
		ans[sum] = num;
	}

	int T;
	cin >> T;
	while(T--) {
		int x;
		cin >> x;
		cout << ans[x] << "\n";
	}

	return 0;
}