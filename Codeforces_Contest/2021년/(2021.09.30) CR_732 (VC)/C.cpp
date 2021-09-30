#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int arr[100001];
int idx[100001][2];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		MEMSET(idx, 0);
		int N;
		cin >> N;
		FOR(i, 1, N) {
			cin >> arr[i];
			idx[arr[i]][i % 2] += 1;
		}
		sort(arr + 1, arr + N + 1);
		bool flag = true;
		FOR(i, 1, N) {
			if (!idx[arr[i]][i % 2]) {
				flag = false;
				break;
			}
			idx[arr[i]][i % 2]--;
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}