#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define LEN(s) int(s.size())
#define pii pair<int, int>

int arr[101];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int a, b;
		FOR(i, 1, N) {
			cin >> arr[i];
			if (i == 1)
				a = arr[i];
			else {
				if (arr[i] != a)
					b = arr[i];
			}
		}
		int a_cnt = 0;
		int b_cnt = 0;
		int a_idx = 0;
		int b_idx = 0;
		FOR(i, 1, N) {
			if (arr[i] == a) {
				a_cnt++;
				a_idx = i;
			}
				
			else if (arr[i] == b) {
				b_cnt++;
				b_idx = i;
			}
		}
		if (a_cnt == 1)
			cout << a_idx;
		else if (b_cnt == 1)
			cout << b_idx;
		cout << "\n";
	}


	return 0;
}