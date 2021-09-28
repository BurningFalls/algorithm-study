#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int arr[101];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int one_cnt = 0;
		int two_cnt = 0;
		FOR(i, 1, N) {
			cin >> arr[i];
			if (arr[i] == 1)
				one_cnt++;
			else if (arr[i] == 2)
				two_cnt++;
		}
		if ((two_cnt % 2 == 0 && one_cnt % 2 == 0) ||
			(two_cnt % 2 == 1 && one_cnt != 0 && one_cnt % 2 == 0))
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}

	return 0;
}